#pragma once

#include <ostream>
#include <string>
#include <string_view>

#include "Position.h"

class Token {
    public:
        enum Kind {
            // reserved words
            BOOLEAN = 0,
            BREAK,
            CONTINUE,
            ELSE,
            FLOAT,
            FOR,
            IF,
            INT,
            RETURN,
            VOID,
            WHILE,

            // operators
            PLUS,
            MINUS,
            MULT,
            DIV,
            NOT,
            NOTEQ,
            EQ,
            EQEQ,
            LT,
            LTEQ,
            GT,
            GTEQ,
            ANDAND,
            OROR,

            // separators
            LCURLY,
            RCURLY,
            LPAREN,
            RPAREN,
            LBRACKET,
            RBRACKET,
            SEMICOLON,
            COMMA,

            // identifiers
            ID,

            // literals
            INTLITERAL,
            FLOATLITERAL,
            BOOLEANLITERAL,
            STRINGLITERAL,

            // special tokens
            ERROR,
            END_OF_FILE
        };

        int kind;
        std::string spelling;
        Position position;

        Token(int token_kind, std::string token_spelling, Position token_pos);

        static std::string_view spell(int token_kind);

        std::string toString() const;

    private:
        int determineKeywordKind(std::string spelling);

        static const std::string_view keywords[];

        static constexpr int firstReservedWord = BOOLEAN;
        static constexpr int lastReservedWord = WHILE;
};

std::ostream& operator<<(std::ostream& os, const Token& t);
