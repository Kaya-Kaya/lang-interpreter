#ifndef VALUE_H
#define VALUE_H

#include "type/bool.hpp"
#include "type/number.hpp"

#include <variant>

using Value = std::variant<NumberType, BoolType>;

enum class Type {
    NUMBER,
    BOOL
};

class TypedValue {
private:
    Value _value;
    Type _type;

public:
    TypedValue(Value value, Type type);

    Value getValue() const;
    Type getType() const;

    TypedValue logicalNot() const;
    TypedValue logicalOr(const TypedValue& other) const;
    TypedValue logicalAnd(const TypedValue& other) const;

    TypedValue add(const TypedValue& other) const;
    TypedValue subtract(const TypedValue& other) const;
    TypedValue multiply(const TypedValue& other) const;
    TypedValue divide(const TypedValue& other) const;
};

#endif
