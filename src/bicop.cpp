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
#include <boost/python.hpp>

#include "bicop_wrap.hpp"

namespace pyvinecopulib 
{
    void export_bicop_class()
    {
        boost::python::class_<bicop_wrap/*, boost::noncopyable*/>("bicop")
            // ctors
            .def(boost::python::init<vinecopulib::BicopFamily>())
            .def(boost::python::init<vinecopulib::BicopFamily, int>())
            .def(boost::python::init<vinecopulib::BicopFamily, int, Eigen::MatrixXd>())
            .def(boost::python::init<Eigen::Matrix<double, Eigen::Dynamic, 2>>())
            .def(boost::python::init<Eigen::Matrix<double, Eigen::Dynamic, 2>, vinecopulib::FitControlsBicop>())
            // properties
            .add_property("rotation",      &bicop_wrap::get_rotation,   &bicop_wrap::set_rotation)
            .add_property("parameters",    &bicop_wrap::get_parameters, &bicop_wrap::set_parameters)
            .add_property("family",        &bicop_wrap::get_family)
            .add_property("family_name",   &bicop_wrap::get_family_name)
            // methods
            .def("pdf",                    &bicop_wrap::pdf)
            .def("hfunc1",                 &bicop_wrap::hfunc1)
            .def("hfunc2",                 &bicop_wrap::hfunc2)
            .def("hinv1",                  &bicop_wrap::hinv1)
            .def("hinv2",                  &bicop_wrap::hinv2)
            .def("simulate",               &bicop_wrap::simulate)
            .def("fit",                    &bicop_wrap::fit)
            .def("select",                 &bicop_wrap::select)
            .def("loglik",                 &bicop_wrap::loglik)
            .def("aic",                    &bicop_wrap::aic)
            .def("bic",                    &bicop_wrap::bic)
            .def("__str__",                &bicop_wrap::str)
            .def("calculate_npars",        &bicop_wrap::calculate_npars)
            .def("parameters_to_tau",      &bicop_wrap::parameters_to_tau)
            .def("tau_to_parameters",      &bicop_wrap::tau_to_parameters)
            .def("flip",                   &bicop_wrap::flip)
        ;
    }
}
