#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include <unordered_map>
#include <variant>

class Context {
private:
    std::unordered_map<std::string, std::variant<int>> _variables;

public:
    template <typename T>
    T lookup(const std::string& name) const;
    void assign();
};

#endif
