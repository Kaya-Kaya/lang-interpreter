#ifndef BOOL_EXPRESSION_H
#define BOOL_EXPRESSION_H

#include "context.hpp"
#include "expression/expression.hpp"
#include "value.hpp"

class NotExpression : UnaryExpression {
    TypedValue interpret(Context& context) const;
};

class OrExpression : BinaryExpression {
    TypedValue interpret(Context& context) const;
};

class AndExpression : BinaryExpression {
    TypedValue interpret(Context& context) const;
};

#endif
