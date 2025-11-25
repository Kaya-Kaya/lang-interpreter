#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>
#include <string>

#include "context.hpp"

template <typename T>
class Expression {
public:
    Expression<T>();

    virtual T interpret(Context context);
};


template <typename T>
class TerminalExpression : Expression<T> {
private:
    T _value;

public:
    TerminalExpression<T>(T value);

    T interpret(Context context);
};


template <typename T>
class VariableExpression : Expression<T> {
private:
    T _name;

public:
    VariableExpression<T>(const std::string& name);

    T interpret(Context context);
};


template <typename T>
class UnaryExpression : Expression<T> {
private:
    std::unique_ptr<Expression<T>> _right;

public:
    UnaryExpression<T>(const Expression<T>* expression);
};


template <typename T>
class BinaryExpression : Expression<T> {
private:
    std::unique_ptr<Expression<T>> _left;
    std::unique_ptr<Expression<T>> _right;

public:
    BinaryExpression<T>(const Expression<T>* left, const Expression<T>* right);
};

#endif
