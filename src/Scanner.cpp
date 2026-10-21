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
            currentSpelling += currentChar;
            accept();
            return Token::LPAREN;

        case '"':
            // TODO
            return handleString();

        case ')':
            currentSpelling += currentChar;
            accept();
            return Token::RPAREN;

        case '{':
            currentSpelling += currentChar;
            accept();
            return Token::LCURLY;

        case '}':
            currentSpelling += currentChar;
            accept();
            return Token::RCURLY;

        case '[':
            currentSpelling += currentChar;
            accept();
            return Token::LBRACKET;

        case ']':
            currentSpelling += currentChar;
            accept();
            return Token::RBRACKET;

        case ';':
            currentSpelling += currentChar;
            accept();
            return Token::SEMICOLON;

        case ',':
            currentSpelling += currentChar;
            accept();
            return Token::COMMA;

        case '.':
            // TODO: consume float
            return handleFLoat();

        case '+':
            currentSpelling += currentChar;
            accept();
            return Token::PLUS;

        case '-':
            currentSpelling += currentChar;
            accept();
            return Token::MINUS;

        case '*':
            currentSpelling += currentChar;
            accept();
            return Token::MULT;

        case '/':
            currentSpelling += currentChar;
            accept();
            return Token::DIV;

        case '|':
            currentSpelling += currentChar;
            accept();
            if (currentChar == '|') {
                currentSpelling += currentChar;
                accept();
                return Token::OROR;
            } else {
                return Token::ERROR;
            }

        case '&':
            currentSpelling += currentChar;
            accept();
            if (currentChar == '&') {
                currentSpelling += currentChar;
                accept();
                return Token::ANDAND;
            } else {
                return Token::ERROR;
            }

        case '<':
            currentSpelling += currentChar;
            accept();
            if (currentChar == '=') {
                currentSpelling += currentChar;
                accept();
                return Token::LTEQ;
            } else {
                return Token::LT;
            }

        case '>':
            currentSpelling += currentChar;
            accept();
            if (currentChar == '=') {
                currentSpelling += currentChar;
                accept();
                return Token::GTEQ;
            } else {
                return Token::GT;
            }

        case '=':
            currentSpelling += currentChar;
            accept();
            if (currentChar == '=') {
                currentSpelling += currentChar;
                accept();
                return Token::EQEQ;
            } else {
                return Token::EQ;
            }

        case '!':
            currentSpelling += currentChar;
            accept();
            if (currentChar == '=') {
                currentSpelling += currentChar;
                accept();
                return Token::NOTEQ;
            } else {
                return Token::NOT;
            }

        case Source::eof:
            currentSpelling += Token::spell(Token::END_OF_FILE);
            return Token::END_OF_FILE;

        default:
            break;
    }

    // handle float/int literals
    if (std::isdigit(static_cast<unsigned char>(currentChar))) {
        while (std::isdigit(static_cast<unsigned char>(currentChar))) {
            currentSpelling += currentChar;
            accept();
        }

        // there is a non numeric char, try float instead
        if (currentChar == '.' || currentChar == 'e' || currentChar == 'E') {
            return handleFLoat();
        }
        return Token::INTLITERAL;
    }

    // handle identifiers
    if (std::isalpha(static_cast<unsigned char>(currentChar)) || currentChar == '_') {
        while (std::isalnum(static_cast<unsigned char>(currentChar)) || currentChar == '_') {
            currentSpelling += currentChar;
            accept();
        }

        if (currentSpelling == "true" || currentSpelling == "false") {
            return Token::BOOLEANLITERAL;
        }

        return Token::ID;
    }

    currentSpelling += currentChar;
    accept();
    return Token::ERROR;
}

void Scanner::skipSpaceAndComments() {
    while (true) {
        // handle whitespace
        while (currentChar == ' ' || currentChar == '\n' || currentChar == '\t' || currentChar == '\r' || currentChar == '\f') {
            // TODO: add stuff for handling tabs etc
            if (currentChar == '\n') {
                lineStart++;
                lineFinish++;
                charStart = 0;
                charFinish = 0;
                accept();
            } else {
                accept();
            }
        }

        // TODO: add stuff for handling comments

        break;
    }
}

Token Scanner::getToken() {
    // TODO
    return Token(Token::END_OF_FILE, std::string(Token::spell(Token::END_OF_FILE)), Position());
}
