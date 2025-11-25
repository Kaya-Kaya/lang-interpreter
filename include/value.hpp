#ifndef VALUE_H
#define VALUE_H

#include <variant>

class TypedValue {
private:
    enum class Type {
        NUMBER
    };
    Type _type;

    using Value = std::variant<double>;
    Value _value;

public:
    TypedValue(Type type, Value value) : _value(value), _type(type) {}
};

#endif
