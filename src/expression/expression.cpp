#include "expression/expression.hpp"
#include "context.hpp"
#include "value.hpp"

#include <string>

TerminalExpression::TerminalExpression(TypedValue value) : _value(value) {}

TypedValue TerminalExpression::interpret(Context& context) const {
    return _value;
}


VariableExpression::VariableExpression(const std::string& name) : _name(name) {}

TypedValue VariableExpression::interpret(Context& context) const {
    return context.lookup(_name);
}

const std::string& VariableExpression::getName() const {
    return _name;
}


UnaryExpression::UnaryExpression(const Expression* expression) : _right(expression) {}


BinaryExpression::BinaryExpression(const Expression* left, const Expression* right)
    : _left(left), _right(right) {}

