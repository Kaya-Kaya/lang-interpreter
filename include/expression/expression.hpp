#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "context.hpp"
#include "value.hpp"

#include <memory>
#include <string>

class Expression {
public:
    Expression();

    virtual TypedValue interpret(Context& context) const;
};


class TerminalExpression : Expression {
private:
    TypedValue _value;

public:
    TerminalExpression(TypedValue value);

    TypedValue interpret(Context& context) const;
};


class VariableExpression : Expression {
private:
    std::string _name;

public:
    VariableExpression(const std::string& name);

    TypedValue interpret(Context& context) const;
    const std::string& getName() const;
};


class UnaryExpression : Expression {
protected:
    std::unique_ptr<const Expression> _right;

public:
    UnaryExpression(const Expression* expression);
};


class BinaryExpression : Expression {
protected:
    std::unique_ptr<const Expression> _left;
    std::unique_ptr<const Expression> _right;

public:
    BinaryExpression(const Expression* left, const Expression* right);
};

#endif
