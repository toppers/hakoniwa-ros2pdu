cmake_minimum_required(VERSION 3.5)
project(msg_conv_test)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(can_msgs REQUIRED)
find_package(ev3_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(hako_msgs REQUIRED)

add_executable(msg_conv_test_node 
  src/msg_conv_test.cpp
)
ament_target_dependencies(msg_conv_test_node 
  rclcpp 
  std_msgs 
  can_msgs
  ev3_msgs
  hako_msgs
)

if (DEFINED ENV{ENV_HAKO_SOURCE_DIR})
  set(HAKO_SOURCE_DIR "$ENV{ENV_HAKO_SOURCE_DIR}")
else()
  set(HAKO_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../hakoniwa-core-cpp-client")
endif()
target_link_directories(msg_conv_test_node
  PRIVATE
  ${HAKO_SOURCE_DIR}/cmake-build/core/src
)
MESSAGE(STATUS  "env hako dir:  $ENV{ENV_HAKO_SOURCE_DIR}")
MESSAGE(STATUS  "hako dir: " ${HAKO_SOURCE_DIR})

target_link_libraries(msg_conv_test_node 
  hako
)

target_include_directories(msg_conv_test_node
  PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../pdu/types>
  $<BUILD_INTERFACE:${HAKO_SOURCE_DIR}/hakoniwa-core-cpp-client/core/src/include>
)

install(TARGETS
  msg_conv_test_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
