file(GLOB_RECURSE files_cpp_src "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE files_c_src "${PROJECT_SOURCE_DIR}/src/*.c")
file(GLOB_RECURSE files_hpp "${PROJECT_SOURCE_DIR}/include/Graphics/*.hpp")
file(GLOB_RECURSE files_h "${PROJECT_SOURCE_DIR}/include/Graphics/*.h")


set(mid_file_save_path ${PROJECT_SOURCE_DIR}/python/cmake_generated)

#for Bind numpy
list(APPEND INCLUDE_DIR  /home/collin/Space_1_5_T/MySoftware/python/numpy/numpy/core/include)

foreach(file ${files_cpp_src})
     list(APPEND srcs ${file} " ")
endforeach(file)
foreach(file ${files_c_src})
    list(APPEND srcs ${file} " ")
endforeach(file)
file(WRITE ${mid_file_save_path}/srcs.txt ${srcs})

##--------------headers.h---------------------
#foreach(file ${files_hpp})
#    list(APPEND incs "#include \"${file}\"\n")
#endforeach(file)
#foreach(file ${files_h})
#    list(APPEND incs "#include \"${file}\" \n")
#endforeach(file)
#file(WRITE ${mid_file_save_path}/headers.h ${incs})

###--------------incs_for_wrap.i---------------------
#foreach(file ${files_hpp})
#    list(APPEND incs_2 "%include \"${file}\"\n")
#endforeach(file)
#foreach(file ${files_h})
#    list(APPEND incs_2 "%include \"${file}\" \n")
#endforeach(file)
#file(WRITE ${mid_file_save_path}/incs_for_wrap.i ${incs_2})


###--------------inc_dirs.txt---------------------
#foreach(file ${INCLUDE_DIR})
#    list(APPEND inc_dirs ${file} " ")
#endforeach(file)
#file(WRITE ${mid_file_save_path}/inc_dirs.txt ${inc_dirs})

##--------------libs-------------------
foreach(file ${LIBRARIES})
    list(APPEND libs ${file} " ")
endforeach(file)
list(APPEND libs ${PROJECT_SOURCE_DIR}/lib/libmyclib.so " "
                 ${PROJECT_SOURCE_DIR}/lib/libmycpplib.so " ")

list(APPEND libs )
file(WRITE ${mid_file_save_path}/libs.txt ${libs})
file(WRITE ${mid_file_save_path}/libmyclib.conf ${PROJECT_SOURCE_DIR}/lib)