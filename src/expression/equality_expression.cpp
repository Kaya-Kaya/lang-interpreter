#include "expression/equality_expression.hpp"
#include "context.hpp"
#include "value.hpp"

TypedValue IsEqualExpression::interpret(Context& context) const {
    return _left->interpret(context).isEqual(_right->interpret(context));
}

TypedValue IsNotEqualExpression::interpret(Context& context) const {
    return _left->interpret(context).isNotEqual(_right->interpret(context));
}

TypedValue IsLessExpression::interpret(Context& context) const {
    return _left->interpret(context).isLess(_right->interpret(context));
}

TypedValue IsGreaterExpression::interpret(Context& context) const {
    return _left->interpret(context).isGreater(_right->interpret(context));
}

TypedValue IsLessOrEqualExpression::interpret(Context& context) const {
    return _left->interpret(context).isLessOrEqual(_right->interpret(context));
}

TypedValue IsGreaterOrEqualExpression::interpret(Context& context) const {
    return _left->interpret(context).isGreaterOrEqual(_right->interpret(context));
}

