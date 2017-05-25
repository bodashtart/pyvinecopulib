# pyvinecopulib
Python bindings for vinecopulib

[![Build Status](https://travis-ci.org/vinecopulib/pyvinecopulib.svg?branch=master)](https://travis-ci.org/vinecopulib/pyvinecopulib)
[![Windows Build status](http://ci.appveyor.com/api/projects/status/github/vinecopulib/pyvinecopulib?branch=master&svg=true)](https://ci.appveyor.com/project/vinecopulib/pyvinecopulib/branch/master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) 
 
#### What is pyvinecopulib?

Pyvinecopulib is a thin Python wrapper around the [vinecopulib](http://github.com/vinecopulib/vinecopulib) C++ library.

Pyvinecopulib is written in C++ and is based on the [Boost.Python](http://boost.org/libs/python) package.

#### Status

Pre-alpha.

All developed functionalities are available for Linux, OSX and Windows.

The aim is to support both Python 2 and 3, as of time of writing continuous integration is only done for Python 2 , though.

#### Documentation

## Getting started

### Requirements

To build pyvinecopulib, you'll need:
* vinecopulib and its dependencies: [C++11 compiler](https://en.wikipedia.org/wiki/List_of_compilers#C.2B.2B_compilers), [CMake](http://cmake.org), [Boost](http://boost.org) headers, [NLopt](https://github.com/stevengj/nlopt), [Eigen](http://eigen.tuxfamily.org)
* [Boost.Python](http://boost.org/libs/python)
* [Python](http://python.org)

Python version and CPU architecture have to match the version used for building Boost.Python.

The additional dependencies are readily available for all target platforms:
* Linux:
   * Debian: [libboost-python-dev](http://packages.debian.org/libboost-python-dev) package
   * Ubuntu: [libboost-python-dev](packages.ubuntu.com/libboost-python-dev) package
   * Fedora: [boost-python](https://apps.fedoraproject.org/packages/boost-python) - not tested!
   * ...
* OSX:
   * Homebrew: [Boost.Python](http://brewformulas.org/BoostPython) package
   * ...
* Windows:
   * Boost.Python [binaries from SF.net](https://sourceforge.net/projects/boost/files/boost-binaries/)
   * matching [Python installer](https://www.python.org/downloads/windows/) - check the Boost DEPENDENCY_VERSIONS.txt file

### Building the library

### Running the tests

### Installation

## Usage examples
