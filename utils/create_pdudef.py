import json
import pandas as pd
import argparse

PDU_METADATA_SIZE = 24

def calc_base_data_size(offset_path):
    try:
        with open(offset_path, "r") as f:
            max_end = 0
            for line in f:
                if not line.strip() or line.startswith("#"):
                    continue  # 空行やコメントは無視

                parts = line.strip().split(":")
                if len(parts) < 6:
                    continue  # 不正行はスキップ

                array_type = parts[0]
                offset = int(parts[4])
                size = int(parts[5])

                if array_type == "varray":
                    field_end = offset + 8  # 参照情報
                else:
                    field_end = offset + size

                max_end = max(max_end, field_end)

            return max_end
    except Exception as e:
        raise RuntimeError(f"Failed to calculate size for {offset_path}: {e}")

def fill_pdu_sizes(df: pd.DataFrame, offset_root: str) -> pd.DataFrame:
    for idx, row in df.iterrows():
        pdu_size = row["pdu_size"]
        if pd.isna(pdu_size) or pdu_size == 0:
            offset_path = f"{offset_root}/{row['package_name']}/{row['type_name']}.offset"
            try:
                base_size = calc_base_data_size(offset_path)
                df.at[idx, "pdu_size"] = base_size
            except Exception as e:
                raise ValueError(f"[{row['package_name']}/{row['type_name']}] のサイズ計算失敗: {e}")
    return df

def validate_csv(df):
    """Validate the CSV content."""
    required_columns = ["RobotName", "package_name", "type_name", "pdu_name", "channel_id", "read_or_write", "pdu_size", "io_cycle"]
    missing_columns = [col for col in required_columns if col not in df.columns]
    
    if missing_columns:
        raise ValueError(f"Missing required columns: {', '.join(missing_columns)}")

    # Validate data types
    for col in ["channel_id", "pdu_size", "io_cycle"]:
        if not pd.api.types.is_numeric_dtype(df[col]):
            raise ValueError(f"Column '{col}' must contain numeric values.")

    for col in ["RobotName", "package_name", "type_name", "pdu_name", "read_or_write"]:
        if not pd.api.types.is_string_dtype(df[col]):
            raise ValueError(f"Column '{col}' must contain string values.")

    # Validate read_or_write values
    valid_rw_values = {"read", "write"}
    if not df["read_or_write"].str.lower().isin(valid_rw_values).all():
        raise ValueError("Column 'read_or_write' must contain only 'read' or 'write'.")

    # `RobotName` も含めて重複チェック
    duplicate_channel_ids = df[df.duplicated(subset=["RobotName", "channel_id", "read_or_write"], keep=False)]

    if not duplicate_channel_ids.empty:
        duplicate_info = duplicate_channel_ids[["RobotName", "channel_id", "pdu_name"]].to_string(index=False)
        raise ValueError(f"Duplicate channel_id found (within the same RobotName):\n{duplicate_info}")

def convert_csv_to_json(csv_file_path, output_json_path, offset_root):
    df = pd.read_csv(csv_file_path)
    validate_csv(df)
    df = fill_pdu_sizes(df, offset_root=offset_root)

    output = {"robots": []}
    grouped = df.groupby("RobotName")
    for robot_name, group in grouped:
        robot_data = {
            "name": robot_name,
            "rpc_pdu_readers": [],
            "rpc_pdu_writers": [],
            "shm_pdu_readers": [],
            "shm_pdu_writers": []
        }

        for _, row in group.iterrows():
            heap_size = int(row["heap_size"]) if "heap_size" in row and not pd.isna(row["heap_size"]) else 0
            total_size = int(row["pdu_size"]) + heap_size + PDU_METADATA_SIZE
            pdu_entry = {
                "type": f"{row['package_name']}/{row['type_name']}",
                "org_name": row["pdu_name"],
                "name": f"{row['RobotName']}_{row['pdu_name']}",
                "channel_id": int(row["channel_id"]),
                "pdu_size": total_size,
                "write_cycle": int(row["io_cycle"]),
                "method_type": "SHM"
            }

            if row["read_or_write"].lower() == "write":
                robot_data["shm_pdu_writers"].append(pdu_entry)
            elif row["read_or_write"].lower() == "read":
                robot_data["shm_pdu_readers"].append(pdu_entry)

        output["robots"].append(robot_data)

    with open(output_json_path, "w") as json_file:
        json.dump(output, json_file, indent=4)

def main():
    parser = argparse.ArgumentParser(description="Convert a CSV file to a JSON file for PDU configuration.")
    parser.add_argument("input_csv", help="Path to the input CSV file.")
    parser.add_argument("--output_json", default="./custom.json", help="Path to the output JSON file (default: ./custom.json).")
    parser.add_argument("--offset_root", default="pdu/offset", help="Path to the offset root directory")

    args = parser.parse_args()

    try:
        convert_csv_to_json(args.input_csv, args.output_json, args.offset_root)
        print(f"JSON file has been generated at: {args.output_json}")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
