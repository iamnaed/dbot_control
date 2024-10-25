cmake_minimum_required(VERSION 3.8)
project(dbot_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(dbot_control_lib REQUIRED)

# Src
add_executable(
  dbot_control_node 
  src/dbot_control_node.cpp
)

target_include_directories(
  dbot_control_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(
  dbot_control_node 
  PUBLIC 
  c_std_99 
  cxx_std_17
)  # Require C99 and C++17

ament_target_dependencies(
  dbot_control_node
  dbot_control_lib
  rclcpp
)

# Install
install(
  TARGETS dbot_control_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()