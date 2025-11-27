#include "context.hpp"
#include "expression/expression.hpp"
#include "expression/number_expression.hpp"
#include "type/number.hpp"
#include "value.hpp"

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<AddExpression> exp = std::make_unique<AddExpression>(
            std::make_unique<TerminalExpression>(TypedValue(NumberType(3), Type::NUMBER)),
            std::make_unique<TerminalExpression>(TypedValue(NumberType(4), Type::NUMBER))
    );

    Context context;
    TypedValue result = exp->interpret(context);

    std::cout << get<NumberType>(result.getValue()).getValue() << std::endl;
}
