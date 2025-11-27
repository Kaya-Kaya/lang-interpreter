#ifndef BOOL_H
#define BOOL_H

#include "type/type.hpp"

class BoolType : public BaseType<bool> {
public:
    using BaseType::BaseType;

    TypedValue logicalNot() const;
    TypedValue logicalOr(const TypedValue other) const;
    TypedValue logicalAnd(const TypedValue other) const;

    TypedValue add(const TypedValue other) const;
    TypedValue subtract(const TypedValue other) const;
    TypedValue multiply(const TypedValue other) const;
    TypedValue divide(const TypedValue other) const;

    TypedValue isEqual(const TypedValue other) const;
    TypedValue isNotEqual(const TypedValue other) const;
    TypedValue isLess(const TypedValue other) const;
    TypedValue isGreater(const TypedValue other) const;
    TypedValue isLessOrEqual(const TypedValue other) const;
    TypedValue isGreaterOrEqual(const TypedValue other) const;
};

#endif
