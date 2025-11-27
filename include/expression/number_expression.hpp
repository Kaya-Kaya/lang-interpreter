#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "context.hpp"
#include "expression/expression.hpp"
#include "value.hpp"

class AddExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

class SubtractExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

class MultiplyExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

class DivideExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

#endif
