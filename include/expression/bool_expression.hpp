#ifndef BOOL_EXPRESSION_H
#define BOOL_EXPRESSION_H

#include "context.hpp"
#include "expression/expression.hpp"
#include "value.hpp"

class NotExpression : public UnaryExpression {
public:
    using UnaryExpression::UnaryExpression;

    TypedValue interpret(Context& context) const override;
};

class OrExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

class AndExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

#endif
