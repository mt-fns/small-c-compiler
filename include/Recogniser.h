#pragma once

#include <string>
#include <iostream>

#include "ErrorReporter.h"
#include "Scanner.h"
#include "Token.h"

class Recogniser {
    public:
        Recogniser(Scanner& scanner, ErrorReporter& reporter);

        // PARSE FUNCTIONS
        void parseProgram();
        void parseType();
        void parseIdent();
        
        void parseFuncDelcRest();
        void parseVarDeclRest();

    private:
        void match(int tokenExpected);
        void accept();
        
        // TODO
        void syntacticError(std::string message, std::string token);

        Scanner& scanner;
        ErrorReporter& reporter;
        Token currentToken;
};