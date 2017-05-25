# pyvinecopulib
Python bindings for vinecopulib

[![Build Status](https://travis-ci.org/vinecopulib/pyvinecopulib.svg?branch=master)](https://travis-ci.org/vinecopulib/pyvinecopulib)
[![Windows Build status](http://ci.appveyor.com/api/projects/status/github/vinecopulib/pyvinecopulib?branch=master&svg=true)](https://ci.appveyor.com/project/vinecopulib/pyvinecopulib/branch/master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) 
 
#### What is pyvinecopulib?

pyvinecopulib is a thin Python wrapper around the [vinecopulib](http://github.com/vinecopulib/vinecopulib) C++ library.

pyvinecopulib is written in C++ and is based on the [Boost.Python](http://boost.org/libs/python) package.

#### Status

Pre-alpha.

The developed functionality is available for Linux, OSX and Windows.

The aim is to support both Python 2 and 3. Continuous integration at present is only supported for Python 2 though.

#### Documentation

- [Getting started](#getting-started)
	- [Requirements](#requirements)
	- [Building the library](#building-the-library)
	- [Running tests](#running-tests)
 - [Installation](#installation)
- [Usage examples](#usage-examples)
 - [Bivariate copula models](#bivariate-copula-models)
	 - [Implemented bivariate copula families](#implemented-bivariate-copula-families)
	 - [Set up a custom bivariate copula model](#set-up-a-custom-bivariate-copula-model)
	 - [Fit and select a bivariate copula](#fit-and-select-a-bivariate-copula)
	 - [Work with a bivariate copula model](#work-with-a-bivariate-copula-model)
 - [Vine copula models](#vine-copula-models)
	 - [Set up a custom vine copula model](#set-up-a-custom-vine-copula-model)
	 - [How to read the R-vine matrix](#how-to-read-the-r-vine-matrix)
	 - [Fit and select a vine copula model](#fit-and-select-a-vine-copula-model)
	 - [Work with a vine copula model](#work-with-a-vine-copula-model)


------------------------------------------------

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

The following usage examples follow the examples setup in the [README file](https://github.com/vinecopulib/vinecopulib/blob/master/README.md) for vinecopulib.

### Bivariate copula models

#### Implemented bivariate copula families


**Example**

#### Set up a custom bivariate copula model


**Example**


#### Fit and select a bivariate copula

**Example**

#### Work with a bivariate copula model

### Vine copula models

#### Set up a custom vine copula model

#### How to read the R-vine matrix

#### Fit and select a vine copula model

#### Work with a vine copula model
