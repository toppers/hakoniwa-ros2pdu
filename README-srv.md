# 📄 README - `generate_hako_service_msgs.py` 

## Overview
This tool generates the necessary `.msg` files for a Hakoniwa Service implementation based on a given ROS `.srv` file.  
It parses the `.srv` definition and outputs request, response, and packet message files, following the Hakoniwa messaging convention.

---

## Purpose and Assumptions

- This tool aims to **reuse existing ROS `.srv` files** for building Hakoniwa Service communication structures easily.
- **ROS IDL compatibility** is **guaranteed** at the `.srv` structure level:
  - Request and response field types and structures follow ROS `.srv` IDL conventions.
  - Runtime compatibility with ROS service protocols is **not** guaranteed.
- The generated `.msg` files are intended **only for Hakoniwa Service RPC communication**, not for direct communication with ROS service nodes.

---

## Intended Use Case

- If a developer already has a ROS `.srv` file for a service,
- They can use this tool to automatically generate Hakoniwa Service `.msg` files,
- Then, they can easily implement and simulate RPC communication using the Hakoniwa Service API within the Hakoniwa simulation environment.
- This reduces the cost of adapting existing ROS service designs into the Hakoniwa ecosystem.

---

## Usage

```bash
python generate_hako_service_msgs.py <path_to_srv_file> --out <output_base_directory>
```

### Example

```bash
python generate_hako_service_msgs.py hako_srv/AddTwoInts.srv --out dest/
```

This will create:

```
dest/
└── hako_srv_msgs/
    ├── AddTwoIntsRequest.msg
    ├── AddTwoIntsResponse.msg
    ├── AddTwoIntsRequestPacket.msg
    └── AddTwoIntsResponsePacket.msg
```

---

## Specification

- The input is a standard ROS `.srv` file.
- The parent directory name of the `.srv` file is treated as the **service package name** (e.g., `hako_srv`).
- The corresponding **message package name** is automatically derived by appending `_msgs` (e.g., `hako_srv_msgs`).
- The tool creates a subdirectory under the given output base directory to store all generated `.msg` files.
- The following four `.msg` files are generated:
  - `<ServiceName>Request.msg`
  - `<ServiceName>Response.msg`
  - `<ServiceName>RequestPacket.msg`
  - `<ServiceName>ResponsePacket.msg`
- `ServiceRequestHeader.msg` and `ServiceResponseHeader.msg` are **NOT generated** by this tool (they are provided by the Hakoniwa system).

---

## Parsing Rules

- Lines starting with `#` are treated as comments and ignored.
- Empty lines are ignored.
- Field definitions must be in the format: `<type> <name>`.
- **Constants** (e.g., `int8 FOO=1`) are ignored and not included in the generated `.msg` files.
- If the request or response contains no data fields (excluding constants), the tool will raise an error.

---

## Field Naming Rules

- Primitive types (`int32`, `string`, etc.) are written as-is.
- Types from **the same message package** omit the package prefix.
- Types from **different packages** (e.g., `std_msgs/Header`) must include the full package prefix.
- Arrays are supported:
  - Variable-length arrays: `type[] field_name`
  - Fixed-length arrays: `type[N] field_name`

---

## Error Handling

- If no request fields or no response fields are found, an error will occur.
- Output directory and subdirectories will be automatically created if they do not exist.
- Existing `.msg` files will be overwritten without prompt.
