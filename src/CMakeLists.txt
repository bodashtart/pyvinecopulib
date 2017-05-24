add_library(pyvinecopulib SHARED 
  version.cpp 
  bicop.cpp 
  vinecop.cpp 
  eigen_converters.cpp 
  pyvinecopulib.cpp 
  tools.cpp 
  family_enums.cpp 
  bicop_fit_controls.cpp
  vinecop_fit_controls.cpp
)

if (APPLE)
  set_target_properties(pyvinecopulib PROPERTIES SUFFIX ".so") # defaults to .dylib which is not looked for by Python
elseif (WIN32)
  set_target_properties(pyvinecopulib PROPERTIES SUFFIX ".pyd") # defaults to .dll which is not looked for by Python
  target_compile_definitions(pyvinecopulib PRIVATE BOOST_ALL_NO_LIB=1)
endif()
if (NOT WIN32)
  set_target_properties(pyvinecopulib PROPERTIES PREFIX "")
endif()


# vinecopulib
target_link_libraries(pyvinecopulib ${VINECOPULIB_LIBRARIES} ${NLOPT_LIBRARIES})
target_include_directories(pyvinecopulib PUBLIC ${VINECOPULIB_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR} ${NLOPT_INCLUDE_DIR})


# informing the Python bindings where to find Python
target_include_directories(pyvinecopulib SYSTEM PUBLIC ${PYTHON_INCLUDE_DIRS})
target_link_libraries(pyvinecopulib ${PYTHON_LIBRARIES})


# informing the Python bindings where to find Boost.Python 
target_link_libraries(pyvinecopulib ${Boost_LIBRARIES})
target_include_directories(pyvinecopulib SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})


# NumPy
execute_process (
    COMMAND ${PYTHON_EXECUTABLE} -c
        "import numpy, sys; sys.stdout.write(numpy.get_include())"
    OUTPUT_VARIABLE NUMPY_INCLUDE_DIR
    RESULT_VARIABLE TMP_STATUS
)
if (NOT TMP_STATUS EQUAL 0)
    message(FATAL_ERROR "NumPy not found!")
endif()
unset(TMP_STATUS)
file ( TO_CMAKE_PATH "${NUMPY_INCLUDE_DIR}" NUMPY_INCLUDE_DIR )
target_include_directories(pyvinecopulib SYSTEM PUBLIC ${NUMPY_INCLUDE_DIR})


# installation (see http://www.cmake.org/pipermail/cmake/2013-March/054138.html)
# <TEMP>
if (NOT WIN32)
# </TEMP>
execute_process (
   COMMAND ${PYTHON_EXECUTABLE} -c
   	"import site, sys; sys.stdout.write(site.PREFIXES[-1])"
   OUTPUT_VARIABLE PYTHON_PREFIX
)
file ( TO_CMAKE_PATH "${PYTHON_PREFIX}" PYTHON_PREFIX )
execute_process (
   COMMAND ${PYTHON_EXECUTABLE} -c
   	"import site, sys; sys.stdout.write(site.getsitepackages()[-1])"
   OUTPUT_VARIABLE PYTHON_SITE_DIR
)
file ( TO_CMAKE_PATH "${PYTHON_SITE_DIR}" PYTHON_SITE_DIR )
string ( REGEX REPLACE "^${PYTHON_PREFIX}/" ""
   PYTHON_SITE_DIR "${PYTHON_SITE_DIR}"
)

install ( TARGETS pyvinecopulib
   LIBRARY
     DESTINATION ${PYTHON_SITE_DIR}
     COMPONENT library
)
else()
  message(WARNING "Python package installation temporarily disabled on Windows")
endif()

if (APPLE)
  set_target_properties(pyvinecopulib PROPERTIES INSTALL_RPATH "${VINECOPULIB_LIB_PATH};${PYTHON_SITE_DIR}")
  set_target_properties(pyvinecopulib PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
endif()
