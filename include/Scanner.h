#pragma once

#include <string>

#include "Position.h"
#include "Source.h"
#include "Token.h"

class ErrorReporter;

class Scanner final {
    public:
        Scanner(Source& source, ErrorReporter& reporter);

        void enableDebugging();

        Token getToken();

    private:
        Source& sourceFile;
        ErrorReporter& errorReporter;
        bool debug;

        std::string currentSpelling;
        char currentChar;
        Position sourcePos;

        int lineStart, lineFinish;
        int charStart, charFinish;

        void accept();

        int handleFLoat();

        char inspectChar(int nthChar);

        int handleString();

        int nextToken();

        void skipSpaceAndComments();
};
