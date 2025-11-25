#include "context.hpp"

template <typename T>
T Context::lookup(const std::string& name) const {
    return std::get<T>(_variables.at(name));
}

