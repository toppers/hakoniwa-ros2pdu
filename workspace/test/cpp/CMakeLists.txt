cmake_minimum_required(VERSION 3.10)
project(PduTest CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# プロジェクトのルートディレクトリをインクルードパスに追加
include_directories(
    ${CMAKE_SOURCE_DIR}/../../../
    ${CMAKE_SOURCE_DIR}/../../../pdu/types
)

add_executable(pdu_tester generate_and_validate_pdu.cpp)
