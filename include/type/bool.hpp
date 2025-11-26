#ifndef BOOL_H
#define BOOL_H

#include "type/type.hpp"

class BoolType : BaseType<bool> {
public:
    using BaseType::BaseType;

    TypedValue logicalNot() const;
    TypedValue logicalOr(const TypedValue& other) const;
    TypedValue logicalAnd(const TypedValue& other) const;
};

#endif
