#include "expression/bool_expression.hpp"
#include "context.hpp"
#include "value.hpp"

TypedValue NotExpression::interpret(Context& context) const {
    return _right->interpret(context).logicalNot();
}

TypedValue OrExpression::interpret(Context& context) const {
    return _left->interpret(context).logicalOr(_right->interpret(context));
}

TypedValue AndExpression::interpret(Context& context) const {
    return _left->interpret(context).logicalAnd(_right->interpret(context));
}

