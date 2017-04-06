/*
* The MIT License (MIT)
*
* Author: Sylwester Arabas, Ahmad Farhat
* Copyright © 2017 Chatham Financial
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <boost/python.hpp>

#include <vinecopulib/bicop/class.hpp>

namespace pyvinecopulib
{
    namespace bp = boost::python;

    struct bicop_wrap : vinecopulib::Bicop, bp::wrapper<vinecopulib::Bicop>
    {
        bicop_wrap(const vinecopulib::Bicop &bicop) : vinecopulib::Bicop(bicop) {}

        bicop_wrap() : vinecopulib::Bicop() {}

        bicop_wrap(const vinecopulib::BicopFamily &family) : vinecopulib::Bicop(family) {}
        bicop_wrap(const vinecopulib::BicopFamily &family, const int &rotation) : vinecopulib::Bicop(family, rotation) {}
        bicop_wrap(const vinecopulib::BicopFamily &family, const int &rotation, const Eigen::MatrixXd &parameters) : vinecopulib::Bicop(family, rotation, parameters) {}

        bicop_wrap(const Eigen::Matrix<double, Eigen::Dynamic, 2> &data) : vinecopulib::Bicop(data) {}
        bicop_wrap(const Eigen::Matrix<double, Eigen::Dynamic, 2> &data, const vinecopulib::FitControlsBicop &controls) : vinecopulib::Bicop(data, controls) {}

        void fit(const Eigen::Matrix<double, Eigen::Dynamic, 2> &data) { vinecopulib::Bicop::fit(data); }
        void select(Eigen::Matrix<double, Eigen::Dynamic, 2> data) { vinecopulib::Bicop::select(data); }
    };
}
