#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "context.hpp"
#include "value.hpp"

#include <memory>
#include <string>

class Expression {
public:
    Expression();

    virtual TypedValue interpret(Context context);
};


class TerminalExpression : Expression {
private:
    TypedValue _value;

public:
    TerminalExpression(TypedValue value);

    TypedValue interpret(Context context);
};


class VariableExpression : Expression {
private:
    std::string _name;

public:
    VariableExpression(const std::string& name);

    TypedValue interpret(Context context);
};


class UnaryExpression : Expression {
private:
    std::unique_ptr<const Expression> _right;

public:
    UnaryExpression(const Expression* expression);
};


class BinaryExpression : Expression {
private:
    std::unique_ptr<const Expression> _left;
    std::unique_ptr<const Expression> _right;

public:
    BinaryExpression(const Expression* left, const Expression* right);
};

#endif
