#include <boost/python.hpp>

#include <vinecopulib/bicop/fit_controls.hpp>

#include "stl_converters.hpp"

namespace pyvinecopulib 
{
    namespace bp = boost::python;

    // TODO: reuse!
    template <typename T>
    struct to_bplist_converter
    {
        static PyObject* convert(std::vector<T> const &vec)
        {
            return bp::incref(to_bplist(vec).ptr());
        }
    };


    struct bfit_controls_wrap : vinecopulib::FitControlsBicop, bp::wrapper<vinecopulib::FitControlsBicop>
    {
        bfit_controls_wrap() : vinecopulib::FitControlsBicop() {}

        bfit_controls_wrap(const bp::list &list) 
          : vinecopulib::FitControlsBicop(to_stdvec<vinecopulib::BicopFamily>(list)) {}
        bfit_controls_wrap(const bp::list &list, const std::string &str) 
          : vinecopulib::FitControlsBicop(to_stdvec<vinecopulib::BicopFamily>(list), str) {}
        bfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl) 
          : vinecopulib::FitControlsBicop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl) {}
        bfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl, const std::string &str2) 
          : vinecopulib::FitControlsBicop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl, str2) {}
        bfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl, const std::string &str2, const bool &bl) 
          : vinecopulib::FitControlsBicop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl, str2, bl) {}

        bfit_controls_wrap(const std::string &str) : vinecopulib::FitControlsBicop(str) {}

        bfit_controls_wrap(const double &dbl) : vinecopulib::FitControlsBicop(dbl) {}

        void set_family_set(const bp::list &list) { vinecopulib::FitControlsBicop::set_family_set(to_stdvec<vinecopulib::BicopFamily>(list)); }
    };

    void export_bicop_fit_controls()
    {
        bp::class_<bfit_controls_wrap, boost::noncopyable>("bicop_fit_controls")
            // ctors
            .def(bp::init<bp::list>())
            .def(bp::init<bp::list, std::string>())
            .def(bp::init<bp::list, std::string, double>())
            .def(bp::init<bp::list, std::string, double, std::string>())
            .def(bp::init<bp::list, std::string, double, std::string, bool>())
            .def(bp::init<std::string>())
            .def(bp::init<double>())
            // properties
            .add_property("parametric_method",   &bfit_controls_wrap::get_parametric_method,   &bfit_controls_wrap::set_parametric_method)
            .add_property("nonparametric_mult",  &bfit_controls_wrap::get_nonparametric_mult,  &bfit_controls_wrap::set_nonparametric_mult)
            .add_property("selection_criterion", &bfit_controls_wrap::get_selection_criterion, &bfit_controls_wrap::set_selection_criterion)
            .add_property("preselect_families",  &bfit_controls_wrap::get_preselect_families,  &bfit_controls_wrap::set_preselect_families)
            .add_property("family_set",          &bfit_controls_wrap::get_family_set,          &bfit_controls_wrap::set_family_set)
        ;

        bp::to_python_converter<std::vector<vinecopulib::BicopFamily>, to_bplist_converter<vinecopulib::BicopFamily>>();
    }
}
