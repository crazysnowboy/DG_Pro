

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -o2 -w ")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w -fPIC")


find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})
list(APPEND INCLUDE_DIR ${INCLUDE_DIR})
