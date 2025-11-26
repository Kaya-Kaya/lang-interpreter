#include "type/bool.hpp"
#include "type/type.hpp"
#include "value.hpp"

TypedValue BoolType::logicalNot() const {
    return TypedValue(BoolType(!getValue()), Type::BOOL);
}

TypedValue BoolType::logicalOr(const TypedValue& other) const {
    switch (other.getType()) {
        case Type::BOOL:
            return TypedValue(BoolType(getValue() || get<BoolType>(other.getValue()).getValue()), Type::BOOL);
        default:
            // error
    }
}

TypedValue BoolType::logicalAnd(const TypedValue& other) const {
    switch (other.getType()) {
        case Type::BOOL:
            return TypedValue(BoolType(getValue() && std::get<BoolType>(other.getValue()).getValue()), Type::BOOL);
        default:
            // error
    }
}

