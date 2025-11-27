#include "expression/expression.hpp"
#include "context.hpp"
#include "value.hpp"

#include <memory>
#include <string>
#include <utility>

TerminalExpression::TerminalExpression(TypedValue value) : _value(value) {}

TypedValue TerminalExpression::interpret(Context& context) const {
    return _value;
}


VariableExpression::VariableExpression(const std::string& name) : _name(std::move(name)) {}

TypedValue VariableExpression::interpret(Context& context) const {
    return context.lookup(_name);
}

const std::string& VariableExpression::getName() const {
    return _name;
}


UnaryExpression::UnaryExpression(std::unique_ptr<Expression> expression) : _right(std::move(expression)) {}


BinaryExpression::BinaryExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
    : _left(std::move(left)), _right(std::move(right)) {}

