#include "Scanner.h"
#include "Colour.h"
#include "ErrorReporter.h"
#include "Position.h"
#include "Token.h"

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

void Scanner::skipChar() {
    if (currentChar == '\n') {
        lineStart++;
        lineFinish++;
        charFinish = 0;
        accept();
    } else if (currentChar == '\t') {
        // move to the column after the next multiple of 8
        int tabCol = charFinish;
        accept();
        charFinish = ((tabCol - 1) / 8 + 1) * 8 + 1;
    } else {
        accept();
    }
}

int Scanner::handleFLoat() {
    // float-const ::= [ int-const ] '.' int-const
    if (!std::isdigit(static_cast<unsigned char>(sourceFile.inspectChar(1)))) {
        if (!currentSpelling.empty()) {
            return Token::INTLITERAL;
        }
        currentSpelling += currentChar;
        accept();
        return Token::ERROR;
    }

    currentSpelling += currentChar;
    accept();
    while (std::isdigit(static_cast<unsigned char>(currentChar))) {
        currentSpelling += currentChar;
        accept();
    }
    return Token::FLOATLITERAL;
}

int Scanner::handleString() {
    // the quotes aren't part of the spelling, and escapes are stored as the char they stand for
    Position start{lineStart, lineFinish, charStart, charStart};
    accept();

    while (currentChar != '"') {
        if (currentChar == '\n' || currentChar == Source::eof) {
            errorReporter.reportError("%: unterminated string", currentSpelling, start);
            return Token::STRINGLITERAL;
        }

        if (currentChar != '\\') {
            currentSpelling += currentChar;
            accept();
            continue;
        }

        char escaped;
        switch (sourceFile.inspectChar(1)) {
            case 'n':  escaped = '\n'; break;
            case 'a':  escaped = '\a'; break;
            case 'b':  escaped = '\b'; break;
            case 't':  escaped = '\t'; break;
            case 'f':  escaped = '\f'; break;
            case 'r':  escaped = '\r'; break;
            case 'v':  escaped = '\v'; break;
            case '\\': escaped = '\\'; break;
            case '\'': escaped = '\''; break;
            case '"':  escaped = '"';  break;
            case '?':  escaped = '?';  break;
            case '0':  escaped = '\0'; break;

            case '\n':
            case Source::eof:
                // leave the newline/eof for the unterminated check
                currentSpelling += currentChar;
                accept();
                continue;

            default: {
                std::string illegal{currentChar, sourceFile.inspectChar(1)};
                Position escapePos{lineStart, lineFinish, charFinish, charFinish + 1};
                errorReporter.reportError("%: illegal escape character", illegal, escapePos);
                currentSpelling += illegal;
                accept();
                accept();
                continue;
            }
        }

        currentSpelling += escaped;
        accept();
        accept();
    }

    accept();
    return Token::STRINGLITERAL;
}

int Scanner::nextToken() {
    switch (currentChar) {
        case '(':
            currentSpelling += currentChar;
            accept();
            return Token::LPAREN;

        case '"':
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
        if (currentChar == '.') {
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

        return Token::ID;
    }

    currentSpelling += currentChar;
    accept();
    return Token::ERROR;
}

void Scanner::skipSpaceAndComments() {
    while (true) {
        if (currentChar == ' ' || currentChar == '\n' || currentChar == '\t' || currentChar == '\r' || currentChar == '\f') {
            skipChar();
        } else if (currentChar == '/' && sourceFile.inspectChar(1) == '/') {
            // the newline is left for the whitespace case
            while (currentChar != '\n' && currentChar != Source::eof) {
                skipChar();
            }
        } else if (currentChar == '/' && sourceFile.inspectChar(1) == '*') {
            Position start{lineStart, lineFinish, charFinish, charFinish};
            skipChar();
            skipChar();

            while (!(currentChar == '*' && sourceFile.inspectChar(1) == '/')) {
                if (currentChar == Source::eof) {
                    errorReporter.reportError("unterminated comment", "", start);
                    return;
                }
                skipChar();
            }
            skipChar();
            skipChar();
        } else {
            break;
        }
    }
}

Token Scanner::getToken() {
    int kind;

    skipSpaceAndComments();

    charStart = charFinish;
    currentSpelling.clear();

    kind = nextToken();

    if (kind == Token::END_OF_FILE) {
        sourcePos = Position{lineStart, lineFinish, 1, 1};
    } else {
        sourcePos = Position{lineStart, lineFinish, charStart, charFinish - 1};
    }

    Token token = Token{kind, currentSpelling, sourcePos};

    if (debug) {
        std::cout << colour::forToken(token.kind) << token << colour::reset() << '\n';
    }

    charStart = charFinish;
    return token;
}
