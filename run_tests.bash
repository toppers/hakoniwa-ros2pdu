#!/bin/bash

# エラーが発生したらスクリプトを停止
set -e

# スクリプトのディレクトリを取得
SCRIPT_DIR=$(cd $(dirname $0); pwd)
cd $SCRIPT_DIR

echo "[INFO] === Step 1: Building C++ tester... ==="
rm -rf workspace/test/build
mkdir -p workspace/test/build
cd workspace/test/build
cmake ../cpp
make


for row in $(cat $SCRIPT_DIR/config/test_cases.json | jq -r '.[] | @base64'); do
    _jq() {
     echo ${row} | base64 --decode | jq -r ${1}
    }

    data_type=$(_jq '.name')
    pdu_file_prefix=$(_jq '.pdu_file_prefix')

    echo "
    [INFO] === Step 2: Running Python serializer (Python -> C++ test) ${data_type} ==="
    PDU_FILE_PREFIX=${pdu_file_prefix} python3 ../py/test_pdu_cross_conversion.py TestPduCrossConversion.test_serialize_${data_type}_from_python


    echo "
    [INFO] === Step 3: Running C++ validator (Python -> C++ test) ${data_type} ==="
    ./pdu_tester validate ${data_type} ${pdu_file_prefix}

    echo "
    [INFO] === Step 4: Running C++ serializer (C++ -> Python test) ${data_type} ==="
    ./pdu_tester generate ${data_type} ${pdu_file_prefix}

    # Step 5: Run Python validator (from build dir)
    echo "
    [INFO] === Step 5: Running Python validator (C++ -> Python test) ${data_type} ==="
    PDU_FILE_PREFIX=${pdu_file_prefix} python3 ../py/test_pdu_cross_conversion.py TestPduCrossConversion.test_deserialize_${data_type}_from_cpp
done


# クリーンアップ
if [ "$1" == "--clean" ]; then
    echo "
[INFO] === Cleaning up generated files... ==="
    rm *.pdu
fi

echo "
[SUCCESS] All cross-language tests passed!"
