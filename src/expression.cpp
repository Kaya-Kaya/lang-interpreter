#include "expression.hpp"
#include "context.hpp"
#include "value.hpp"

TerminalExpression::TerminalExpression(TypedValue value) : _value(value) {}

TypedValue TerminalExpression::interpret(Context context) {
    return _value;
}


VariableExpression::VariableExpression(const std::string& name) : _name(name) {}

TypedValue VariableExpression::interpret(Context context) {
    return context.lookup(_name);
}


UnaryExpression::UnaryExpression(const Expression* expression) : _right(expression) {}


BinaryExpression::BinaryExpression(const Expression* left, const Expression* right)
    : _left(left), _right(right) {}

