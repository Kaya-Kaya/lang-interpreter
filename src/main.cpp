#include "context.hpp"
#include "exception/interpreter_exception.hpp"
#include "expression/expression.hpp"
#include "expression/number_expression.hpp"
#include "expression/equality_expression.hpp"
#include "lexer.hpp"
#include "type/number.hpp"
#include "value.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main() {
    std::unique_ptr<Expression> exp = std::make_unique<IsEqualExpression>(
        std::make_unique<AddExpression>(
            std::make_unique<TerminalExpression>(TypedValue(NumberType(3))),
            std::make_unique<TerminalExpression>(TypedValue(NumberType(4)))
        ),
        std::make_unique<MultiplyExpression>(
            std::make_unique<TerminalExpression>(TypedValue(NumberType(2))),
            std::make_unique<VariableExpression>("x")
        )
    );

    Context context;
    context.assign("x", TypedValue(NumberType(3.5)));

    try {
        TypedValue result = exp->interpret(context);
        std::cout << get<BoolType>(result.getValue()).getValue() << std::endl;
    } catch (const InterpreterException& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    }

    Lexer lexer;
    std::vector<Token> tokens;
    lexer.tokenize("34 30912+321== true", tokens);

    for (const auto& token : tokens) {
        std::string typeName;

        switch (token.type) {
            case TokenType::OPERATOR:
                typeName = "OPERATOR";
                break;
            case TokenType::KEYWORD:
                typeName = "KEYWORD";
                break;
            case TokenType::VARIABLE:
                typeName = "VARIABLE";
                break;
            case TokenType::NUMBER:
                typeName = "NUMBER";
                break;
            case TokenType::BOOL:
                typeName = "BOOL";
                break;
        }

        std::cout << typeName << ' ' << *token.text << std::endl;
    }
}

