CMAKE_MINIMUM_REQUIRED(VERSION 2.6) #cmake 版本限定
PROJECT(MeshPro)  #工程名称


set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
# ---Includes
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/Graphics
        ${PROJECT_SOURCE_DIR}/include/Graphics/HarmonicMapper
        ${PROJECT_SOURCE_DIR}/include/Graphics/DavidMeshLib

        ${PROJECT_SOURCE_DIR}/python/cmake_generated


        )


include(cmake/ConfigureOpenCV.cmake)
include(cmake/MyConfigure.cmake)
include(cmake/ConfigureOpengl.cmake)
#include(cmake/FindEigen3.cmake)

#set(CMAKE_BUILD_TYPE Release) # 等同于 cmake -DCMAKE_BUILD_TYPE=release
#set(CMAKE_VERBOSE_MAKEFILE 1)



include_directories(${INCLUDE_DIR})

include(cmake/ConfigurePython.cmake)


#add_subdirectory(${PROJECT_SOURCE_DIR}/src/c)
#add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp)
#add_subdirectory(${PROJECT_SOURCE_DIR}/main)

#file(GLOB_RECURSE CtoExe_SRCS "${PROJECT_SOURCE_DIR}/src/c/*.c")
file(GLOB_RECURSE CPPtoExe_SRCS "${PROJECT_SOURCE_DIR}/src/cpp/*.cpp")
file(GLOB_RECURSE ForExe_SRCS "${PROJECT_SOURCE_DIR}/main/*.cpp")
set(toExe_SRCS ${CtoExe_SRCS} ${CPPtoExe_SRCS})
foreach(source ${ForExe_SRCS})
    get_filename_component(SourceName ${source} NAME_WE)
    set(ExeName ${SourceName})
    # target
    set(SRCS_ALL ${source} ${toExe_SRCS})
    add_executable(${ExeName} ${SRCS_ALL})
    # link library
    target_link_libraries(${ExeName}
            ${LIBRARIES}
            )
    set_target_properties(${ExeName} PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin"
            LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin"
            RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
endforeach(source)

