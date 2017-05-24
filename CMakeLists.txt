cmake_minimum_required(VERSION 3.2)

project(pyvinecopulib CXX)

set(CMAKE_CXX_STANDARD 11)

if (CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-z,defs")
endif()

enable_testing()

include(cmake/findEigen3.cmake REQUIRED)
find_package(NLopt             REQUIRED)

find_package(vinecopulib REQUIRED)
find_library(VINECOPULIB_LIB_PATH vinecopulib)
get_filename_component(VINECOPULIB_LIB_PATH "${VINECOPULIB_LIB_PATH}" DIRECTORY)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION_STRING} EXACT REQUIRED)

if (APPLE OR (WIN32 AND "${PYTHON_VERSION_MAJOR}" STREQUAL 2)) # Homebrew convention
  set(TMP_BOOST_PYTHON_COMPONENT "python")
elseif (WIN32) # Windows
  set(TMP_BOOST_PYTHON_COMPONENT "python${PYTHON_VERSION_MAJOR}")
else() # Debian convention
  set(TMP_BOOST_PYTHON_COMPONENT "python-py${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}")
endif()
find_package(Boost COMPONENTS ${TMP_BOOST_PYTHON_COMPONENT} REQUIRED)
unset(TMP_BOOST_PYTHON_COMPONENT)

execute_process (
    COMMAND ${PYTHON_EXECUTABLE} -c
        "import platform, sys; sys.stdout.write(platform.architecture()[0])"
	OUTPUT_VARIABLE PYTHON_ARCHITECTURE
        RESULT_VARIABLE TMP_STATUS
    )
if (NOT TMP_STATUS EQUAL 0)
  message(FATAL_ERROR "Failed to detect Python architecture!")
endif()
math(EXPR VOID_P_BITS "${CMAKE_SIZEOF_VOID_P} * 8")
if (NOT "${CMAKE_SIZEOF_VOID_P}" STREQUAL "8" AND "${PYTHON_ARCHITECTURE}" STREQUAL "64bit")
	message(FATAL_ERROR "Python architecutre (${PYTHON_ARCHITECTURE}) does not match build architecture (${VOID_P_BITS}bit)")
endif()


add_subdirectory(src)
add_subdirectory(tests)
