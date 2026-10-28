#include "Token.h"

#include <sstream>

const std::string_view Token::keywords[] = {
    "break",
    "continue",
    "else",
    "float",
    "for",
    "if",
    "int",
    "return",
    "void",
    "while",
    "+",
    "-",
    "*",
    "/",
    "!",
    "!=",
    "=",
    "==",
    "<",
    "<=",
    ">",
    ">=",
    "&&",
    "||",
    "{",
    "}",
    "(",
    ")",
    "[",
    "]",
    ";",
    ",",
    "<id>",
    "<int-literal>",
    "<float-literal>",
    "<string-literal>",
    "<error>",
    "$"
};

Token::Token(int token_kind, std::string token_spelling, Position token_pos) :
    kind{token_kind},
    spelling{token_spelling},
    position(token_pos) {
    if (token_kind == Token::ID) {
        kind = determineKeywordKind(spelling);
    }
}

std::string_view Token::spell(int token_kind) {
    static_assert(std::size(keywords) == END_OF_FILE + 1);
    return keywords[token_kind];
}

std::string Token::toString() const {
    std::ostringstream out;
    out << "type = " << spell(kind) << ", token = \""
        << spelling << "\", position = [" << position << "]";
    return out.str();
}

int Token::determineKeywordKind(std::string spelling) {
    for (int i = firstReservedWord; i <= lastReservedWord; i++) {
        if (keywords[i] == spelling) {
            return i;
        }
    }

    return Token::ID;
}

std::ostream& operator<<(std::ostream& os, const Token& t) {
    return os << t.toString();
}
