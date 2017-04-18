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

#include <vinecopulib/vinecop/class.hpp>

#include "bicop_wrap.hpp"

namespace pyvinecopulib
{
    namespace bp = boost::python;

    std::vector<std::vector<vinecopulib::Bicop>> object_to_vector_of_vector_of_Bicop(const bp::list& pair_copulas)
    {
        std::vector<std::vector<vinecopulib::Bicop>> ret(bp::len(pair_copulas));

        for (decltype(ret.size()) i=0; i<ret.size(); ++i)
        {
            auto list = bp::extract<bp::list>(pair_copulas[i])();
            ret[i].resize(bp::len(list));
            for (decltype(bp::len(list)) j=0; j<bp::len(list); ++j)
            {
                auto elem = list[j];
                ret[i][j] = bp::extract<bicop_wrap>(elem)();
            }
        }

        return ret;
    }

    struct vector_of_vectors_of_Bicop_to_list_of_lists_of_bicop
    {
        static PyObject* convert(std::vector<std::vector<vinecopulib::Bicop>> const &vec)
        {
            bp::list list;
            for (auto i=0; i < vec.size(); ++i)
            {
                bp::list sublist;
                for (auto j=0; j < vec[i].size(); ++j)
                    sublist.append(bp::object(/*bicop_wrap(vec[i][j])*/));
                //bp::incref(sublist.ptr());
                list.append(sublist);
            }
            return bp::incref(list.ptr());
        }
    };


    struct vinecop_wrap : vinecopulib::Vinecop, bp::wrapper<vinecopulib::Vinecop>
    {
        vinecop_wrap() : vinecopulib::Vinecop() {}

        vinecop_wrap(size_t d) : vinecopulib::Vinecop(d) {}

        vinecop_wrap(const bp::list& pair_copulas, const Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic>& matrix)
            : vinecopulib::Vinecop(
                object_to_vector_of_vector_of_Bicop(pair_copulas), 
                matrix
            )
        { }

        vinecop_wrap(const Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic> &matrix) : vinecopulib::Vinecop(matrix) {}

        vinecop_wrap(const Eigen::MatrixXd &data) : vinecopulib::Vinecop(data) {}
        
        vinecop_wrap(const Eigen::MatrixXd &data, const vinecopulib::FitControlsBicop &controls) : vinecopulib::Vinecop(data, controls) {}

        vinecop_wrap(
            const Eigen::MatrixXd &data, 
            const Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic>& matrix
        ) : vinecopulib::Vinecop(data, matrix) {}

        vinecop_wrap(
            const Eigen::MatrixXd &data, 
            const Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic>& matrix,
            const vinecopulib::FitControlsBicop &controls
        ) : vinecopulib::Vinecop(data, matrix, controls) {}

        void select_all_1arg(const Eigen::MatrixXd& data) { vinecopulib::Vinecop::select_all(data); }

        void select_all_2arg(const Eigen::MatrixXd& data, const vinecopulib::FitControlsVinecop &controls) { vinecopulib::Vinecop::select_all(data, controls); }

        void select_families_1arg(const Eigen::MatrixXd& data) { vinecopulib::Vinecop::select_families(data); }

        void select_families_2arg(const Eigen::MatrixXd& data, const vinecopulib::FitControlsVinecop &controls) { vinecopulib::Vinecop::select_families(data, controls); }
    };

    void export_vinecop_class()
    {
        // TODO: bp::return_value_policy<bp::manage_new_object>() ???

        bp::class_<vinecop_wrap, boost::noncopyable>("vinecop")
            // ctors
            .def(bp::init<size_t>())
            .def(bp::init<bp::list, Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic>>()) 
            .def(bp::init<Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic>>())
            .def(bp::init<Eigen::MatrixXd>())
            .def(bp::init<Eigen::MatrixXd, vinecopulib::FitControlsVinecop>())
            .def(bp::init<Eigen::MatrixXd, Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic>>())
            .def(bp::init<Eigen::MatrixXd, Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic>, vinecopulib::FitControlsVinecop>())
            // properties
            .add_property("all_pair_copulas", &vinecop_wrap::get_all_pair_copulas)
            .add_property("all_parameters",   &vinecop_wrap::get_all_parameters)
            .add_property("all_rotations",    &vinecop_wrap::get_all_rotations)
            .add_property("all_families",     &vinecop_wrap::get_all_families)
            .add_property("matrix",           &vinecop_wrap::get_matrix)
            // methods
            .def("rotation",               &vinecop_wrap::get_rotation)
            .def("parameters",             &vinecop_wrap::get_parameters)
            .def("all_parameters",         &vinecop_wrap::get_all_parameters)
            .def("family",                 &vinecop_wrap::get_family)
            .def("pdf",                    &vinecop_wrap::pdf)
            .def("simulate",               &vinecop_wrap::simulate) 
            .def("inverse_rosenblatt",     &vinecop_wrap::inverse_rosenblatt)
            .def("select_families",        &vinecop_wrap::select_families_1arg)
            .def("select_families",        &vinecop_wrap::select_families_2arg)
            .def("select_all",             &vinecop_wrap::select_all_1arg)
            .def("select_all",             &vinecop_wrap::select_all_2arg)
            .def("calculate_npars",        &vinecop_wrap::calculate_npars)
            .def("loglik",                 &vinecop_wrap::loglik)
            .def("aic",                    &vinecop_wrap::aic)
            .def("bic",                    &vinecop_wrap::bic)
            // static methods
            .def("make_pair_copula_store", &vinecop_wrap::make_pair_copula_store)
            .staticmethod("make_pair_copula_store")
        ;
 
        bp::to_python_converter<
            std::vector<std::vector<vinecopulib::Bicop>>, 
            vector_of_vectors_of_Bicop_to_list_of_lists_of_bicop
        >();
    }
}
