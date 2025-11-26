#include "type/number.hpp"
#include "type/type.hpp"
#include "value.hpp"

TypedValue NumberType::add(const TypedValue& other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(NumberType(getValue() + get<NumberType>(other.getValue()).getValue()), Type::NUMBER);
        default:
            // error
    }
}

TypedValue NumberType::subtract(const TypedValue& other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(NumberType(getValue() - get<NumberType>(other.getValue()).getValue()), Type::NUMBER);
        default:
            // error
    }
}

TypedValue NumberType::multiply(const TypedValue& other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(NumberType(getValue() * get<NumberType>(other.getValue()).getValue()), Type::NUMBER);
        default:
            // error
    }
}

TypedValue NumberType::divide(const TypedValue& other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(NumberType(getValue() / get<NumberType>(other.getValue()).getValue()), Type::NUMBER);
        default:
            // error
    }
}
