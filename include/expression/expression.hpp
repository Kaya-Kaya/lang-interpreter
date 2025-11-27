#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "context.hpp"
#include "value.hpp"

#include <memory>
#include <string>

class Expression {
public:
    virtual ~Expression() = default;

    virtual TypedValue interpret(Context& context) const = 0;
};


class TerminalExpression : public Expression {
private:
    TypedValue _value;

public:
    TerminalExpression(TypedValue value);

    TypedValue interpret(Context& context) const override;
};


class VariableExpression : public Expression {
private:
    std::string _name;

public:
    VariableExpression(const std::string& name);

    TypedValue interpret(Context& context) const override;
    const std::string& getName() const;
};


class UnaryExpression : public Expression {
protected:
    std::unique_ptr<const Expression> _right;

public:
    UnaryExpression(std::unique_ptr<Expression> expression);
};


class BinaryExpression : public Expression {
protected:
    std::unique_ptr<const Expression> _left;
    std::unique_ptr<const Expression> _right;

public:
    BinaryExpression(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
};

#endif
