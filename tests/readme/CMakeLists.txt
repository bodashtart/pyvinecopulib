file(GLOB_RECURSE file_list "${CMAKE_CURRENT_SOURCE_DIR}/*.py")
foreach (test_filename ${file_list})
  pyvinecopulib_add_test(${test_filename})
endforeach()
