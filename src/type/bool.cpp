#include "exception/runtime_exception.hpp"
#include "type/bool.hpp"
#include "type/type.hpp"
#include "value.hpp"

TypedValue BoolType::logicalNot() const {
    return TypedValue(BoolType(!getValue()));
}

TypedValue BoolType::logicalOr(const TypedValue other) const {
    switch (other.getType()) {
        case Type::BOOL:
            return TypedValue(BoolType(getValue() || get<BoolType>(other.getValue()).getValue()));
        default:
            throw InvalidOperationException("Invalid operation: Cannot perform logical OR with non-boolean");
    }
}

TypedValue BoolType::logicalAnd(const TypedValue other) const {
    switch (other.getType()) {
        case Type::BOOL:
            return TypedValue(BoolType(getValue() && std::get<BoolType>(other.getValue()).getValue()));
        default:
            throw InvalidOperationException("Invalid operation: Cannot perform logical AND with non-boolean");
    }
}

TypedValue BoolType::isEqual(const TypedValue other) const {
    switch (other.getType()) {
        case Type::BOOL:
            return TypedValue(BoolType(getValue() == std::get<BoolType>(other.getValue()).getValue()));
        default:
            // might change later
            return TypedValue(BoolType(false));
    }
}

TypedValue BoolType::isNotEqual(const TypedValue other) const {
    switch (other.getType()) {
        case Type::BOOL:
            return TypedValue(BoolType(getValue() != std::get<BoolType>(other.getValue()).getValue()));
        default:
            // might change later
            return TypedValue(BoolType(true));
    }
}

TypedValue BoolType::isLess(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Cannot compare booleans");
}

TypedValue BoolType::isGreater(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Cannot compare booleans");
}

TypedValue BoolType::isLessOrEqual(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Cannot compare booleans");
}

TypedValue BoolType::isGreaterOrEqual(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Cannot compare booleans");
}

TypedValue BoolType::negate() const {
    throw InvalidOperationException("Invalid operation: Cannot negate booleans");
}

TypedValue BoolType::add(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Cannot add booleans");
}

TypedValue BoolType::subtract(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Cannot subtract booleans");
}

TypedValue BoolType::multiply(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Cannot multiply booleans");
}

TypedValue BoolType::divide(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Cannot divide booleans");
}

TypedValue BoolType::power(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Cannot exponentiate booleans");
}

