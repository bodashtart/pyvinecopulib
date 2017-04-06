#pragma once

#include <boost/python.hpp>
#include <vector>

namespace pyvinecopulib
{
    namespace bp = boost::python;

    template <typename T>
    std::vector<T> to_stdvec(const bp::list& iterable)
    {
        return std::vector<T>(bp::stl_input_iterator<T>(iterable),
                              bp::stl_input_iterator<T>());
    }

    template <typename T>
    bp::list to_bplist(std::vector<T> const &vec)
    {
        bp::list list;
        for (auto i=0; i < vec.size(); ++i)
            list.append(bp::object(vec[i]));
        return list;
    };
}
