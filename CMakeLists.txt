cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(segmentation)

add_compile_options(-fPIC)
set(CMAKE_CXX_STANDARD 17)
set(CXX_FLAGS "-std=c++17 -lstdc++fs")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -g -pthread")
set(CMAKE_BUILD_TYPE "Debug")
set(PACKAGE_VERSION 1.0)


find_package(PCL 1.12 REQUIRED)
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

find_package(Eigen3 REQUIRED)

include_directories(
	include
    ${PCL_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS}
)

aux_source_directory(./src DIR_SRC)
add_executable( ${PROJECT_NAME} ${DIR_SRC})
target_link_libraries(${PROJECT_NAME}
  ${PCL_LIBRARIES}
  stdc++fs
)
