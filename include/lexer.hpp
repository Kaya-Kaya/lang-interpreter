#ifndef LEXER_H
#define LEXER_H

#include <array>
#include <memory>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#define TOKEN_TYPE_COUNT (5)

enum class TokenType {
    OPERATOR,
    KEYWORD,
    VARIABLE,
    NUMBER,
    BOOL,
};

constexpr std::array<std::pair<TokenType, std::string_view>, TOKEN_TYPE_COUNT> regexes{
    std::pair{ TokenType::OPERATOR, "^(==|!=|>=|<=|and|or|>|<|[+\\-*\\/^=!])" },
    std::pair{ TokenType::KEYWORD, "" },
    std::pair{ TokenType::NUMBER, "^(\\d+)" },
    std::pair{ TokenType::BOOL, "^(true|false)" },
    std::pair{ TokenType::VARIABLE, "^([a-zA-Z_]\\w*)" },
};

struct Token {
    std::string_view text;
    TokenType type;

    Token(std::string_view text, TokenType type);
};

namespace re2 {
    class RE2;
}

class Lexer {
private:
    std::array<std::unique_ptr<re2::RE2>, TOKEN_TYPE_COUNT> _compiledRegexes;

public:
    Lexer();
    ~Lexer();

    /**
     * Populates the token vector from the given string.
     */
    void tokenize(const std::string_view input, std::vector<Token>& tokensOut);
};

#endif
