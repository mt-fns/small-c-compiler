#include "Scanner.h"

#include <cctype>
#include <iostream>

Scanner::Scanner(Source& source, ErrorReporter& reporter) :
    sourceFile{source},
    errorReporter{reporter},
    debug{false},
    currentChar{source.getNextChar()},
    lineStart{1},
    lineFinish{1},
    charStart{1},
    charFinish{1} {}

void Scanner::enableDebugging() {
    debug = true;
}

void Scanner::accept() {
    currentChar = sourceFile.getNextChar();
    charFinish++;
}

int Scanner::handleFLoat() {
    // TODO
    return Token::FLOATLITERAL;
}

char Scanner::inspectChar(int nthChar) {
    return sourceFile.inspectChar(nthChar);
}

int Scanner::handleString() {
    // TODO
    return Token::STRINGLITERAL;
}

int Scanner::nextToken() {
    switch (currentChar) {
        case '(':
            break;
        case '"':
            break;
        case ')':
            break;
        case '}':
            break;
        case '{':
            break;
        case '[':
            break;
        case ']':
            break;
        case ';':
            break;
        case '.':
            break;
        case '+':
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        case '|':
            break;
        default:
            break;
    }

    return Token::ERROR;
}

void Scanner::skipSpaceAndComments() {
    // TODO
}

Token Scanner::getToken() {
    // TODO
    return Token(Token::END_OF_FILE, std::string(Token::spell(Token::END_OF_FILE)), Position());
}
