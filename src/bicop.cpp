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

#include <vinecopulib/bicop/class.hpp>
#include <vinecopulib/vinecop/class.hpp>

namespace 
{
    namespace bp = boost::python;

    struct bicop_wrap : vinecopulib::Bicop, bp::wrapper<vinecopulib::Bicop>
    {
        bicop_wrap() : vinecopulib::Bicop() {}

        bicop_wrap(const vinecopulib::BicopFamily &family) : vinecopulib::Bicop(family) {}

        bicop_wrap(const vinecopulib::BicopFamily &family, const int &rotation) : vinecopulib::Bicop(family, rotation) {}

        bicop_wrap(const vinecopulib::BicopFamily &family, const int &rotation, const Eigen::MatrixXd &parameters) : vinecopulib::Bicop(family, rotation, parameters) {}

        void fit(const Eigen::Matrix<double, Eigen::Dynamic, 2> &data) { vinecopulib::Bicop::fit(data); }
        void select(Eigen::Matrix<double, Eigen::Dynamic, 2> data) { vinecopulib::Bicop::select(data); }
    };

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

    struct vinecop_wrap : vinecopulib::Vinecop, bp::wrapper<vinecopulib::Vinecop>
    {
        vinecop_wrap() : vinecopulib::Vinecop() {}

        vinecop_wrap(int d) : vinecopulib::Vinecop(d) {}

        vinecop_wrap(const bp::list& pair_copulas, const Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic>& matrix)
            : vinecopulib::Vinecop(
                object_to_vector_of_vector_of_Bicop(pair_copulas), 
                matrix
            )
        { }

        void select_all(const Eigen::MatrixXd& data) { vinecopulib::Vinecop::select_all(data); }
    };
}

void export_family_enums()
{
    boost::python::enum_<vinecopulib::BicopFamily>("BicopFamily")
        .value("indep",    vinecopulib::BicopFamily::indep)
        .value("gaussian", vinecopulib::BicopFamily::gaussian)
        .value("student",  vinecopulib::BicopFamily::student)
        .value("clayton",  vinecopulib::BicopFamily::clayton)
        .value("gumbel",   vinecopulib::BicopFamily::gumbel)
        .value("frank",    vinecopulib::BicopFamily::frank)
        .value("joe",      vinecopulib::BicopFamily::joe)
        .value("bb1",      vinecopulib::BicopFamily::bb1)
        .value("bb6",      vinecopulib::BicopFamily::bb6)
        .value("bb7",      vinecopulib::BicopFamily::bb7)
        .value("bb8",      vinecopulib::BicopFamily::bb8)
        .value("tll0",     vinecopulib::BicopFamily::tll0)
        .export_values()
        ;
}

void export_bicop_class()
{
    boost::python::class_<bicop_wrap, boost::noncopyable>("bicop")
        // ctors
        .def(boost::python::init<vinecopulib::BicopFamily>())
        .def(boost::python::init<vinecopulib::BicopFamily, int>())
        .def(boost::python::init<vinecopulib::BicopFamily, int, Eigen::MatrixXd>())
        //.def(boost::python::init<vinecopulib::BicopFamily, int>())
        //.def(boost::python::init<vinecopulib::BicopFamily, int, Eigen::VectorXd>())
        .add_property("rotation", &vinecopulib::Bicop::get_rotation, &vinecopulib::Bicop::set_rotation)
        .add_property("parameters", &vinecopulib::Bicop::get_parameters, &vinecopulib::Bicop::set_parameters)
        .add_property("family", &vinecopulib::Bicop::get_family)
        .def("simulate", &vinecopulib::Bicop::simulate)
        .def("fit", &bicop_wrap::fit)
        .def("select", &bicop_wrap::select)
    ;

    //bp::to_python_converter<BicopPtr, BicopPtr_to_bicop>();
}

void export_vinecop_class()
{
    boost::python::class_<vinecop_wrap, boost::noncopyable>("vinecop")
        // ctors
        .def(boost::python::init<int>())
        .def(boost::python::init<boost::python::list, Eigen::Matrix<size_t, Eigen::Dynamic, Eigen::Dynamic>>()) 
        // member functions
        .def("rotation",    &vinecopulib::Vinecop::get_rotation)
        .add_property("all_rotations", &vinecopulib::Vinecop::get_all_rotations)
        .def("parameters",  &vinecopulib::Vinecop::get_parameters)
        .def("all_parameters",  &vinecopulib::Vinecop::get_all_parameters)
        .def("family",      &vinecopulib::Vinecop::get_family)
        .add_property("all_families", &vinecopulib::Vinecop::get_all_families)
        .add_property("matrix",       &vinecopulib::Vinecop::get_matrix)
        //.def("pair_copula", &vinecopulib::Vinecop::get_pair_copula)
        .def("pdf",         &vinecopulib::Vinecop::pdf)
        .def("simulate", &vinecopulib::Vinecop::simulate) 
        .def("inverse_rosenblatt", &vinecopulib::Vinecop::inverse_rosenblatt)
        // static methods
        .def("select_all", &vinecop_wrap::select_all); //, (
/*
            boost::python::arg("data"),
            boost::python::arg("family_set"),
            boost::python::arg("method"),
            boost::python::arg("truncation_level"),
            boost::python::arg("matrix"),
            boost::python::arg("selection_criterion"),
            boost::python::arg("preselect_families"),
            boost::python::arg("show_trace")
        )) // TODO: bp::return_value_policy<bp::manage_new_object>()
*/
        //.staticmethod("structure_select")
// TODO is make_pc_store needed???
//        .def("make_pair_copula_store", &vinecopulib::Vinecop::make_pc_store)
//        .staticmethod("make_pc_store")
    ;
}
