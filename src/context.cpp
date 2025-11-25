#include "context.hpp"
#include "value.hpp"

#include <stdexcept>

TypedValue Context::lookup(const std::string& name) const {
    try {
        return _variables.at(name);
    } catch (std::out_of_range& e) {
        // throw error
    }
}

