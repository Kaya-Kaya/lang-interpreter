#include "expression/number_expression.hpp"
#include "value.hpp"

TypedValue AddExpression::interpret(Context& context) const {
    return _left->interpret(context).add(_right->interpret(context));
}

TypedValue SubtractExpression::interpret(Context& context) const {
    return _left->interpret(context).subtract(_right->interpret(context));
}

TypedValue MultiplyExpression::interpret(Context& context) const {
    return _left->interpret(context).multiply(_right->interpret(context));
}

TypedValue DivideExpression::interpret(Context& context) const {
    return _left->interpret(context).divide(_right->interpret(context));
}

