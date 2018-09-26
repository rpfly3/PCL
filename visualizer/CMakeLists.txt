cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(pcl_visualizer_viewports)

SET(CMAKE_PREFIX_PATH "/usr/local/pcl")

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (pcl_visualizer_demo pcl_visualizer_demo.cpp)
add_executable (pcl_visualizer_merge merge.cc)
target_link_libraries (pcl_visualizer_demo ${PCL_LIBRARIES})
target_link_libraries (pcl_visualizer_merge ${PCL_LIBRARIES})
