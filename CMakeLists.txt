cmake_minimum_required(VERSION 3.2)

project(pyvinecopulib CXX)

set(CMAKE_CXX_STANDARD 11)

if (CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-z,defs")
endif()

enable_testing()

include(cmake/findEigen3.cmake            REQUIRED)
include(cmake/findNlopt.cmake             REQUIRED)

find_package(vinecopulib REQUIRED)
find_library(VINECOPULIB_LIB_PATH vinecopulib)
get_filename_component(VINECOPULIB_LIB_PATH "${VINECOPULIB_LIB_PATH}" DIRECTORY)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION_STRING} EXACT REQUIRED)

if (APPLE OR WIN32) # Windows & Homebrew convention
  set(TMP_BOOST_PYTHON_COMPONENT "python")
else() # Debian convention
  set(TMP_BOOST_PYTHON_COMPONENT "python-py${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}")
endif()
find_package(Boost COMPONENTS ${TMP_BOOST_PYTHON_COMPONENT} REQUIRED)
unset(TMP_BOOST_PYTHON_COMPONENT)

add_subdirectory(src)
add_subdirectory(tests)
