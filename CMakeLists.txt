SET(execName PCLTutorial)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4)
PROJECT(${execName})

SET(EXECUTABLE_OUTPUT_PATH ".")
SET(CMAKE_PREFIX_PATH "/usr/local/pcl")

find_package(ZED 2 REQUIRED)
find_package(OpenCV 3.4.1 REQUIRED)
find_package(CUDA ${ZED_CUDA_VERSION} EXACT REQUIRED)
find_package(PCL 1.8 REQUIRED)

include_directories(${CUDA_INCLUDE_DIRS})
include_directories(${PCL_INCLUDE_DIRS})
include_directories(${ZED_INCLUDE_DIRS})
include_directories(${OPENCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${ZED_LIBRARY_DIR})
link_directories(${OpenCV_LIBRARY_DIRS})
link_directories(${CUDA_LIBRARY_DIRS})

ADD_EXECUTABLE(${execName} main.cc)
add_definitions(-std=c++11 -g -O3)


TARGET_LINK_LIBRARIES(${execName}
                        ${ZED_LIBRARIES}
                        ${OpenCV_LIBRARIES}
                        ${PCL_LIBRARIES}
                        ${CUDA_CUDA_LIBRARY} ${CUDA_CUDART_LIBRARY} ${CUDA_NPP_LIBRARIES_ZED} )