#include "lexer.hpp"
#include "re2/stringpiece.h"

#include <cassert>
#include <memory>
#include <re2/re2.h>
#include <string>
#include <utility>
#include <vector>

Token::Token(std::unique_ptr<std::string> text, TokenType type) : text(std::move(text)), type(type) {}

Lexer::Lexer() {
    for (int i = 0; i < TOKEN_TYPE_COUNT; i++) {
        _compiledRegexes[i] = std::make_unique<RE2>(regexes[i].second);
        assert(_compiledRegexes[i]->ok());
    }
}

Lexer::~Lexer() = default;

void Lexer::tokenize(const std::string& input, std::vector<Token>& tokensOut) {
    for (int startIdx = 0; startIdx < input.size(); ) {
        bool matched = false;

        for (int regIdx = 0; regIdx < TOKEN_TYPE_COUNT; regIdx++) {
            re2::StringPiece match;

            if (RE2::PartialMatch(input.substr(startIdx), *_compiledRegexes[regIdx], &match)) {
                tokensOut.emplace_back(std::make_unique<std::string>(match.data(), match.size()), regexes[regIdx].first);
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
