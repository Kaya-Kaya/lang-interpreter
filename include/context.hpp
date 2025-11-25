#ifndef CONTEXT_H
#define CONTEXT_H

#include "value.hpp"

#include <string>
#include <unordered_map>

class Context {
private:
    std::unordered_map<std::string, TypedValue> _variables;

public:
    TypedValue lookup(const std::string& name) const;
    void assign();
};

#endif
