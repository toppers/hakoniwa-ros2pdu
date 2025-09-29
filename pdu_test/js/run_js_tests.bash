#!/bin/bash

set -e

# This script should be run from the project root directory.

TEST_DIR="pdu_test/js"
TEST_TYPES_FILE="${TEST_DIR}/test_types.txt"

# Ensure python packages are discoverable
echo "Creating __init__.py files for Python packages..."
touch pdu/__init__.py
touch pdu/python/__init__.py

# Check if test types file exists
if [ ! -f "$TEST_TYPES_FILE" ]; then
    echo "Error: Test types file not found at $TEST_TYPES_FILE"
    exit 1
fi

echo "Starting PDU JavaScript Converter Tests..."

while IFS= read -r line || [[ -n "$line" ]]; do
    # Skip empty lines
    if [ -z "$line" ]; then
        continue
    fi

    # Split the line into package and message name
    PACKAGE_NAME=$(echo $line | cut -d'/' -f1)
    MESSAGE_NAME=$(echo $line | cut -d'/' -f2)
    JSON_FILE="${TEST_DIR}/${MESSAGE_NAME}.json"
    GOLDEN_BIN="${TEST_DIR}/golden.bin"
    JS_BIN_RESULT="${TEST_DIR}/js_test_result.bin"

    echo "----------------------------------------------------"
    echo "Testing: ${PACKAGE_NAME}/${MESSAGE_NAME}"
    echo "----------------------------------------------------"

    # --- Step 1: Generate Golden Binary using Python ---
    echo "[1/3] Generating golden binary with Python..."
    PYTHONPATH=. python3 -m pdu.python.${PACKAGE_NAME}.pdu_conv_${MESSAGE_NAME} write "${JSON_FILE}" "${GOLDEN_BIN}"
    if [ $? -ne 0 ]; then
        echo "Error: Python serialization failed for ${MESSAGE_NAME}"
        exit 1
    fi
    echo " -> ${GOLDEN_BIN} generated."

    # --- Step 2: Run JavaScript Test (Deserialization, Verification, Serialization) ---
    echo "[2/3] Running JS test (de/serialize & verify)..."
    node "${TEST_DIR}/test_worker.js" "${PACKAGE_NAME}" "${MESSAGE_NAME}" "${JSON_FILE}" "${GOLDEN_BIN}" "${JS_BIN_RESULT}"
    if [ $? -ne 0 ]; then
        echo "Error: Node.js test worker failed for ${MESSAGE_NAME}"
        exit 1
    fi

    # --- Step 3: Verify Serialization (Binary comparison) ---
    echo "[3/3] Verifying serialization (binary cmp)..."
    cmp "${GOLDEN_BIN}" "${JS_BIN_RESULT}"
    if [ $? -ne 0 ]; then
        echo "Error: Binary output does not match for ${MESSAGE_NAME}"
        exit 1
    fi
    echo " -> Binary files match."

    echo " -> SUCCESS: ${PACKAGE_NAME}/${MESSAGE_NAME}"

done < "$TEST_TYPES_FILE"

# Clean up temporary files
rm "${GOLDEN_BIN}" "${JS_BIN_RESULT}"

echo "----------------------------------------------------"

echo "All tests passed successfully!"
