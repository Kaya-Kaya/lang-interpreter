#include "value.hpp"
#include "type/bool.hpp"

TypedValue::TypedValue(Value value, Type type) : _value(value), _type(type) {}

Value TypedValue::getValue() const {
    return _value;
}

Type TypedValue::getType() const {
    return _type;
}

TypedValue TypedValue::logicalNot() const {
    switch (getType()) {
        case Type::BOOL:
            return get<BoolType>(getValue()).logicalNot();
        default:
            // error
    }
}

TypedValue TypedValue::logicalAnd(const TypedValue& other) const {
    switch (getType()) {
        case Type::BOOL:
            return get<BoolType>(getValue()).logicalAnd(other);
        default:
            // error
    }
}

TypedValue TypedValue::logicalOr(const TypedValue& other) const {
    switch (getType()) {
        case Type::BOOL:
            return get<BoolType>(getValue()).logicalOr(other);
        default:
            // error
    }
}

TypedValue TypedValue::add(const TypedValue& other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).add(other);
        default:
            // error
    }
}

TypedValue TypedValue::subtract(const TypedValue& other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).subtract(other);
        default:
            // error
    }
}

TypedValue TypedValue::multiply(const TypedValue& other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).multiply(other);
        default:
            // error
    }
}

TypedValue TypedValue::divide(const TypedValue& other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).divide(other);
        default:
            // error
    }
}

