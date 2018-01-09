#--- (OBSOLETE) find it with PkgConfig
find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENCV REQUIRED opencv)

list(APPEND LIBRARIES ${OPENCV_LDFLAGS})

list(APPEND INCLUDE_DIR ${OPENCV_INCLUDE_DIRS})
#include_directories(${OPENCV_INCLUDE_DIRS})
