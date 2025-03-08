import json
import pandas as pd
import argparse

PDU_METDATA_SIZE = 24

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


def convert_csv_to_json(csv_file_path, output_json_path):
    # Load CSV file
    df = pd.read_csv(csv_file_path)

    # Validate the CSV content
    validate_csv(df)

    # Initialize the output dictionary
    output = {"robots": []}

    # Group by RobotName to process each robot's data
    grouped = df.groupby("RobotName")
    for robot_name, group in grouped:
        robot_data = {
            "name": robot_name,
            "rpc_pdu_readers": [],
            "rpc_pdu_writers": [],
            "shm_pdu_readers": [],
            "shm_pdu_writers": []
        }

        # Process each row for the current robot
        for _, row in group.iterrows():
            pdu_entry = {
                "type": f"{row['package_name']}/{row['type_name']}",
                "org_name": row["pdu_name"],
                "name": f"{row['RobotName']}_{row['pdu_name']}",
                "channel_id": int(row["channel_id"]),
                "pdu_size": int(row["pdu_size"]) + PDU_METDATA_SIZE,
                "write_cycle": int(row["io_cycle"]),
                "method_type": "SHM"
            }

            # Add to appropriate list based on read_or_write
            if row["read_or_write"].lower() == "write":
                robot_data["shm_pdu_writers"].append(pdu_entry)
            elif row["read_or_write"].lower() == "read":
                robot_data["shm_pdu_readers"].append(pdu_entry)

        # Append robot data to output
        output["robots"].append(robot_data)

    # Write output to JSON file
    with open(output_json_path, "w") as json_file:
        json.dump(output, json_file, indent=4)

def main():
    parser = argparse.ArgumentParser(description="Convert a CSV file to a JSON file for PDU configuration.")
    parser.add_argument("input_csv", help="Path to the input CSV file.")
    parser.add_argument("--output_json", default="./custom.json", help="Path to the output JSON file (default: ./custom.json).")

    args = parser.parse_args()

    try:
        convert_csv_to_json(args.input_csv, args.output_json)
        print(f"JSON file has been generated at: {args.output_json}")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
