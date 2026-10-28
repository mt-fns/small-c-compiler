#pragma once

#include <cstddef>
#include <deque>
#include <string>
#include <iostream>

#include "ErrorReporter.h"
#include "Scanner.h"
#include "Token.h"

class Recogniser {
    public:
        Recogniser(Scanner& scanner, ErrorReporter& reporter);

        // PARSE TOP LEVEL
        void parseTopLevel();
        void parseTopLevelElem();


        // PARSE FUNCTIONS
        void parseFunDefinition();


        // PARSE DECLARATIONS
        void parseDeclStmt();

        // PARSE TYPES
        void parseTyyDecl();

        void parseIdentifier();

    
    private:
        // check if tokenExpected == currentToken.kind. if yes, move on to the next token else throw a SyntaxError
        void match(int tokenExpected);

        // move on to next token
        void accept();

        // the nth token after currentToken without consuming anything (n >= 1)
        Token peek(std::size_t n);
        
        // throw a SyntaxError with custom message
        void syntacticError(std::string message, std::string token);

        Scanner& scanner;
        ErrorReporter& reporter;
        Token currentToken;

        // tokens already taken from the scanner by peek() but not yet accepted
        std::deque<Token> lookahead;
};