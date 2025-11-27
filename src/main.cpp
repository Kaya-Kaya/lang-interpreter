#include "context.hpp"
#include "exception/interpreter_exception.hpp"
#include "expression/expression.hpp"
#include "expression/number_expression.hpp"
#include "expression/equality_expression.hpp"
#include "type/number.hpp"
#include "value.hpp"

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<Expression> exp = std::make_unique<IsEqualExpression>(
        std::make_unique<AddExpression>(
            std::make_unique<TerminalExpression>(TypedValue(NumberType(3), Type::NUMBER)),
            std::make_unique<TerminalExpression>(TypedValue(NumberType(4), Type::NUMBER))
        ),
        std::make_unique<MultiplyExpression>(
            std::make_unique<TerminalExpression>(TypedValue(NumberType(2), Type::NUMBER)),
            std::make_unique<VariableExpression>("x")
        )
    );

    Context context;
    context.assign("x", TypedValue(NumberType(3.5), Type::NUMBER));

    try {
        TypedValue result = exp->interpret(context);
        std::cout << get<BoolType>(result.getValue()).getValue() << std::endl;
    } catch (const InterpreterException& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    }
}
