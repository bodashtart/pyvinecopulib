find_package(PythonInterp REQUIRED)

foreach (test_name test_git_revision)#;test_bicop;test_vinecop;test_bicop_readme_example)
  add_test(NAME ${test_name} WORKING_DIRECTORY ${CMAKE_BINARY_DIR} COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/${test_name}.py)

  if (WIN32)
    get_filename_component(TMP_PYTHON_LIB_PATH ${PYTHON_LIBRARIES} DIRECTORY)

    # https://cmake.org/pipermail/cmake/2010-December/041176.html
    set(PATH_STRING "$ENV{PATH};${Boost_LIBRARY_DIRS};${NLOPT_ROOT_DIR};${TMP_PYTHON_LIB_PATH};${VINECOPULIB_LIB_PATH}") 
    string(REPLACE "\\;" ";" PATH_STRING "${PATH_STRING}")
    string(REPLACE ";" "\\;" PATH_STRING "${PATH_STRING}")

    # https://cmake.org/pipermail/cmake-developers/2013-June/019217.html
    set_property(TEST ${test_name} PROPERTY ENVIRONMENT "PATH=${PATH_STRING}")
    set_property(TEST ${test_name} APPEND PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_BINARY_DIR}/src/Debug") #TODO: ${CMAKE_CFG_INTDIR} ?
  else()
    set_property(TEST ${test_name} PROPERTY ENVIRONMENT "PYTHONPATH=${CMAKE_BINARY_DIR}/src")
    if (NOT APPLE)
      set_property(TEST ${test_name} APPEND PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=${VINECOPULIB_LIB_PATH}")
    endif()
  endif()

endforeach()
