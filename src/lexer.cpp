#include "lexer.hpp"

#include <re2/stringpiece.h>
#include <re2/re2.h>
#include <cassert>
#include <memory>
#include <string_view>
#include <utility>
#include <vector>

Token::Token(std::string_view text, TokenType type) : text(std::move(text)), type(type) {}

Lexer::Lexer() {
    for (int i = 0; i < TOKEN_TYPE_COUNT; i++) {
        _compiledRegexes[i] = std::make_unique<RE2>(regexes[i].second);
        assert(_compiledRegexes[i]->ok());
    }
}

Lexer::~Lexer() = default;

void Lexer::tokenize(const std::string_view text, std::vector<Token>& tokensOut) {
    for (int startIdx = 0; startIdx < text.size(); ) {
        bool matched = false;

        for (int regIdx = 0; regIdx < TOKEN_TYPE_COUNT; regIdx++) {
            std::string_view match;

            if (RE2::PartialMatch(text.substr(startIdx), *_compiledRegexes[regIdx], &match)) {
                tokensOut.emplace_back(match, regexes[regIdx].first);
                startIdx += match.size();
                matched = true;
                break;
            }
        }

        if (!matched) {
            startIdx++;
        }
    }
}
