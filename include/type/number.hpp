#ifndef NUMBER_H
#define NUMBER_H

#include "type/type.hpp"

class NumberType : public BaseType<double> {
public:
    using BaseType::BaseType;

    TypedValue logicalNot() const;
    TypedValue logicalOr(const TypedValue other) const;
    TypedValue logicalAnd(const TypedValue other) const;

    TypedValue add(const TypedValue other) const;
    TypedValue subtract(const TypedValue other) const;
    TypedValue multiply(const TypedValue other) const;
    TypedValue divide(const TypedValue other) const;
};

#endif
