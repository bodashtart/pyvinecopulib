#include <boost/python.hpp>

#include <vinecopulib/vinecop/fit_controls.hpp>

#include "stl_converters.hpp"

namespace pyvinecopulib 
{
    namespace bp = boost::python;

    struct vfit_controls_wrap : vinecopulib::FitControlsVinecop, bp::wrapper<vinecopulib::FitControlsVinecop>
    {
        vfit_controls_wrap() : vinecopulib::FitControlsVinecop() {}

        vfit_controls_wrap(const bp::list &list) 
          : vinecopulib::FitControlsVinecop(to_stdvec<vinecopulib::BicopFamily>(list)) {}
        vfit_controls_wrap(const bp::list &list, const std::string &str) 
          : vinecopulib::FitControlsVinecop(to_stdvec<vinecopulib::BicopFamily>(list), str) {}
        vfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl) 
          : vinecopulib::FitControlsVinecop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl) {}
        vfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl, const size_t &size) 
          : vinecopulib::FitControlsVinecop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl, size) {}
        vfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl, const size_t &size, const std::string &str2) 
          : vinecopulib::FitControlsVinecop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl, size, str2) {}
        vfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl, const size_t &size, const std::string &str2, const double &dbl2) 
          : vinecopulib::FitControlsVinecop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl, size, str2, dbl2) {}
        vfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl, const size_t &size, const std::string &str2, const double &dbl2, const std::string &str3) 
          : vinecopulib::FitControlsVinecop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl, size, str2, dbl2, str3) {}
        vfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl, const size_t &size, const std::string &str2, const double &dbl2, const std::string &str3, const bool &bl) 
          : vinecopulib::FitControlsVinecop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl, size, str2, dbl2, str3, bl) {}
        vfit_controls_wrap(const bp::list &list, const std::string &str, const double &dbl, const size_t &size, const std::string &str2, const double &dbl2, const std::string &str3, const bool &bl, const bool &bl2) 
          : vinecopulib::FitControlsVinecop(to_stdvec<vinecopulib::BicopFamily>(list), str, dbl, size, str2, dbl2, str3, bl, bl2) {}

        vfit_controls_wrap(const FitControlsBicop &controls) 
          : vinecopulib::FitControlsVinecop(controls) {}
        vfit_controls_wrap(const FitControlsBicop &controls, const size_t &size) 
          : vinecopulib::FitControlsVinecop(controls, size) {}
        vfit_controls_wrap(const FitControlsBicop &controls, const size_t &size, const std::string &str) 
          : vinecopulib::FitControlsVinecop(controls, size, str) {}
        vfit_controls_wrap(const FitControlsBicop &controls, const size_t &size, const std::string &str, const double &dbl) 
          : vinecopulib::FitControlsVinecop(controls, size, str, dbl) {}
        vfit_controls_wrap(const FitControlsBicop &controls, const size_t &size, const std::string &str, const double &dbl, const bool &bl) 
          : vinecopulib::FitControlsVinecop(controls, size, str, dbl, bl) {}

        void set_family_set(const bp::list &list) { vinecopulib::FitControlsBicop::set_family_set(to_stdvec<vinecopulib::BicopFamily>(list)); }
    };

    void export_vinecop_fit_controls()
    {
        boost::python::class_<vfit_controls_wrap, boost::noncopyable>("vinecop_fit_controls")
            // ctors
            .def(bp::init<bp::list>())
            .def(bp::init<bp::list, std::string>())
            .def(bp::init<bp::list, std::string, double>())
            .def(bp::init<bp::list, std::string, double, size_t>())
            .def(bp::init<bp::list, std::string, double, size_t, std::string>())
            .def(bp::init<bp::list, std::string, double, size_t, std::string, double>())
            .def(bp::init<bp::list, std::string, double, size_t, std::string, double, std::string>())
            .def(bp::init<bp::list, std::string, double, size_t, std::string, double, std::string, bool>())
            .def(bp::init<bp::list, std::string, double, size_t, std::string, double, std::string, bool, bool>())
            .def(bp::init<vinecopulib::FitControlsBicop>())
            .def(bp::init<vinecopulib::FitControlsBicop, size_t>())
            .def(bp::init<vinecopulib::FitControlsBicop, size_t, std::string>())
            .def(bp::init<vinecopulib::FitControlsBicop, size_t, std::string, double>())
            .def(bp::init<vinecopulib::FitControlsBicop, size_t, std::string, double, bool>())
            // properties
            .add_property("truncation_level",    &vfit_controls_wrap::get_truncation_level,    &vfit_controls_wrap::set_truncation_level)
            .add_property("tree_criterion",      &vfit_controls_wrap::get_tree_criterion,      &vfit_controls_wrap::set_tree_criterion)
            .add_property("threshold",           &vfit_controls_wrap::get_threshold,           &vfit_controls_wrap::set_threshold)
            .add_property("show_trace",          &vfit_controls_wrap::get_show_trace,          &vfit_controls_wrap::set_show_trace)
            .add_property("fit_controls_bicop",  &vfit_controls_wrap::get_fit_controls_bicop,  &vfit_controls_wrap::set_fit_controls_bicop)
            // ditto (inherited from bicop)
            .add_property("parametric_method",   &vfit_controls_wrap::get_parametric_method,   &vfit_controls_wrap::set_parametric_method)
            .add_property("nonparametric_mult",  &vfit_controls_wrap::get_nonparametric_mult,  &vfit_controls_wrap::set_nonparametric_mult)
            .add_property("selection_criterion", &vfit_controls_wrap::get_selection_criterion, &vfit_controls_wrap::set_selection_criterion)
            .add_property("preselect_families",  &vfit_controls_wrap::get_preselect_families,  &vfit_controls_wrap::set_preselect_families)
            .add_property("family_set",          &vfit_controls_wrap::get_family_set,          &vfit_controls_wrap::set_family_set)
        ;
    }
}
