#include "value.hpp"
#include "type/bool.hpp"

TypedValue::TypedValue(Value value) : _value(value) {}

Value TypedValue::getValue() const {
    return _value;
}

Type TypedValue::getType() const {
    return (Type) _value.index();
}

TypedValue TypedValue::logicalNot() const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).logicalNot();
        case Type::BOOL:
            return get<BoolType>(getValue()).logicalNot();
    }
}

TypedValue TypedValue::logicalAnd(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).logicalAnd(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).logicalAnd(other);
    }
}

TypedValue TypedValue::logicalOr(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).logicalOr(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).logicalOr(other);
    }
}

TypedValue TypedValue::add(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).add(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).add(other);
    }
}

TypedValue TypedValue::subtract(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).subtract(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).subtract(other);
    }
}

TypedValue TypedValue::multiply(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).multiply(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).multiply(other);
    }
}

TypedValue TypedValue::divide(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).divide(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).divide(other);
    }
}

TypedValue TypedValue::isEqual(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).isEqual(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).isEqual(other);
    }
}


TypedValue TypedValue::isNotEqual(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).isNotEqual(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).isNotEqual(other);
    }
}


TypedValue TypedValue::isLess(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).isLess(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).isLess(other);
    }
}

TypedValue TypedValue::isGreater(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).isGreater(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).isGreater(other);
    }
}

TypedValue TypedValue::isLessOrEqual(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).isLessOrEqual(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).isLessOrEqual(other);
    }
}

TypedValue TypedValue::isGreaterOrEqual(const TypedValue other) const {
    switch (getType()) {
        case Type::NUMBER:
            return get<NumberType>(getValue()).isGreaterOrEqual(other);
        case Type::BOOL:
            return get<BoolType>(getValue()).isGreaterOrEqual(other);
    }
}

