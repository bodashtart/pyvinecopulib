#include <boost/python.hpp>

#include <vinecopulib/bicop/family.hpp>

#include "stl_converters.hpp"

namespace pyvinecopulib
{
    namespace bp = boost::python;



    void export_family_enums()
    {
        bp::enum_<vinecopulib::BicopFamily>("bicop_family")
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

        bp::def("get_family_name", &vinecopulib::get_family_name);

        {
            std::string nested_name = bp::extract<std::string>(bp::scope().attr("__name__") + ".bicop_families");
            bp::object nested_module(bp::handle<>(bp::borrowed(PyImport_AddModule(nested_name.c_str()))));
            bp::scope().attr("bicop_families") = nested_module;
            bp::scope parent = nested_module;

            bp::scope().attr("all"             ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::all);
            bp::scope().attr("parametric"      ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::parametric);
            bp::scope().attr("nonparametric"   ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::nonparametric);
            bp::scope().attr("one_par"         ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::one_par);
            bp::scope().attr("two_par"         ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::two_par);
            bp::scope().attr("elliptical"      ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::elliptical);
            bp::scope().attr("archimedean"     ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::archimedean);
            bp::scope().attr("BB"              ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::BB);
            bp::scope().attr("rotationless"    ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::rotationless);
            bp::scope().attr("lt"              ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::lt);
            bp::scope().attr("ut"              ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::ut);
            bp::scope().attr("itau"            ) = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::itau);
            bp::scope().attr("flip_by_rotation") = to_bplist<vinecopulib::BicopFamily>(vinecopulib::bicop_families::flip_by_rotation);
        }
    }
}
