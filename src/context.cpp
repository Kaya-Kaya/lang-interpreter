#include "expression/expression.hpp"
#include "exception/runtime_exception.hpp"
#include "context.hpp"
#include "value.hpp"

#include <stdexcept>
#include <string>
#include <utility>

TypedValue Context::lookup(const std::string& name) const {
    try {
        return _variables.at(name);
    } catch (std::out_of_range& e) {
        throw UndefinedVariableException(name);
    }
}

void Context::assign(const std::string& name, TypedValue value) {
    _variables.insert(std::pair<std::string, TypedValue>(std::move(name), value));
}

