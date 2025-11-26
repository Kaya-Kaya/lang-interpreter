#ifndef NUMBER_H
#define NUMBER_H

#include "type/type.hpp"

class NumberType : BaseType<double> {
public:
    using BaseType::BaseType;

    TypedValue add(const TypedValue& other) const;
    TypedValue subtract(const TypedValue& other) const;
    TypedValue multiply(const TypedValue& other) const;
    TypedValue divide(const TypedValue& other) const;
};

#endif
