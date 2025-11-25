#include "expression.hpp"
#include "context.hpp"

template <typename T>
TerminalExpression<T>::TerminalExpression(T value) : _value(value) {}

template <typename T>
T TerminalExpression<T>::interpret(Context context) {
    return _value;
}


template <typename T>
VariableExpression<T>::VariableExpression(const std::string& name) : _name(name) {}

template <typename T>
T VariableExpression<T>::interpret(Context context) {
    return context.lookup<T>(_name);
}


template <typename T>
UnaryExpression<T>::UnaryExpression(const Expression<T>* expression) : _right(expression) {}


template <typename T>
BinaryExpression<T>::BinaryExpression(const Expression<T>* left, const Expression<T>* right)
    : _left(left), _right(right) {}

