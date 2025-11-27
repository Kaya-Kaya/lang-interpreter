#ifndef EQUALITY_EXPRESSION_H
#define EQUALITY_EXPRESSION_H

#include "expression/expression.hpp"
#include "value.hpp"

class IsEqualExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

class IsNotEqualExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

class IsLessExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

class IsGreaterExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

class IsLessOrEqualExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

class IsGreaterOrEqualExpression : public BinaryExpression {
public:
    using BinaryExpression::BinaryExpression;

    TypedValue interpret(Context& context) const override;
};

#endif
