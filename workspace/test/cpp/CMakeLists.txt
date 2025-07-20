cmake_minimum_required(VERSION 3.10)
project(PduTest CXX)

# プロジェクトのルートディレクトリをインクルードパスに追加
include_directories(
    ${CMAKE_SOURCE_DIR}/../../../
    ${CMAKE_SOURCE_DIR}/../../../pdu/types
)

add_executable(pdu_tester generate_and_validate_pdu.cpp)
