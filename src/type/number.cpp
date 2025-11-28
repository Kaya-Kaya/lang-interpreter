#include "exception/runtime_exception.hpp"
#include "type/number.hpp"
#include "type/bool.hpp"
#include "type/type.hpp"
#include "value.hpp"

#include <cmath>

TypedValue NumberType::add(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(NumberType(getValue() + get<NumberType>(other.getValue()).getValue()));
        default:
            throw InvalidOperationException("Invalid operation: Cannot add non-number to number");
    }
}

TypedValue NumberType::subtract(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(NumberType(getValue() - get<NumberType>(other.getValue()).getValue()));
        default:
            throw InvalidOperationException("Invalid operation: Cannot subtract non-number from number");
    }
}

TypedValue NumberType::multiply(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(NumberType(getValue() * get<NumberType>(other.getValue()).getValue()));
        default:
            throw InvalidOperationException("Invalid operation: Cannot multiply number by non-number");
    }
}

TypedValue NumberType::divide(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER: {
            double divisor = get<NumberType>(other.getValue()).getValue();
            if (divisor == 0) {
                throw DivisionByZeroException();
            }
            return TypedValue(NumberType(getValue() / divisor));
        }
        default:
            throw InvalidOperationException("Invalid operation: Cannot divide number by non-number");
    }
}

TypedValue NumberType::power(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER: {
            double left = getValue();
            double right = get<NumberType>(other.getValue()).getValue();

            if ((left == 0) && (right == 0)) {
                throw DivisionByZeroException();
            }

            return TypedValue(NumberType(std::pow(left, right)));
        }
        default:
            throw InvalidOperationException("Invalid operation: Cannot divide number by non-number");
    }
}

TypedValue NumberType::isEqual(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(BoolType(getValue() == get<NumberType>(other.getValue()).getValue()));
        default:
            return TypedValue(BoolType(false));
    }
}

TypedValue NumberType::isNotEqual(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(BoolType(getValue() != get<NumberType>(other.getValue()).getValue()));
        default:
            return TypedValue(BoolType(true));
    }
}

TypedValue NumberType::isLess(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(BoolType(getValue() < get<NumberType>(other.getValue()).getValue()));
        default:
            throw InvalidOperationException("Invalid operation: Cannot compare number with non-number");
    }
}

TypedValue NumberType::isGreater(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(BoolType(getValue() > get<NumberType>(other.getValue()).getValue()));
        default:
            throw InvalidOperationException("Invalid operation: Cannot compare number with non-number");
    }
}

TypedValue NumberType::isLessOrEqual(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(BoolType(getValue() <= get<NumberType>(other.getValue()).getValue()));
        default:
            throw InvalidOperationException("Invalid operation: Cannot compare number with non-number");
    }
}

TypedValue NumberType::isGreaterOrEqual(const TypedValue other) const {
    switch (other.getType()) {
        case Type::NUMBER:
            return TypedValue(BoolType(getValue() >= get<NumberType>(other.getValue()).getValue()));
        default:
            throw InvalidOperationException("Invalid operation: Cannot compare number with non-number");
    }
}

TypedValue NumberType::logicalNot() const {
    throw InvalidOperationException("Invalid operation: Logical NOT is not defined for numbers");
}

TypedValue NumberType::logicalAnd(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Logical AND is not defined for numbers");
}

TypedValue NumberType::logicalOr(const TypedValue other) const {
    throw InvalidOperationException("Invalid operation: Logical OR is not defined for numbers");
}

