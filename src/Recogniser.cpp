#include "Recogniser.h"
#include "Position.h"
#include "Source.h"
#include "SyntaxError.h"
#include "Token.h"

Recogniser::Recogniser(Scanner& scanner, ErrorReporter& reporter) :
    scanner{scanner},
    reporter{reporter},
    currentToken{scanner.getToken()} {}

void Recogniser::match(int tokenExpected) {
    if (currentToken.kind == tokenExpected) {
        accept();
    } else {
        // TODO: throw a syntax error here once we have the syntax error class
        std::cerr << "EROR IN MATCH" << std::endl;
    }
}

void Recogniser::accept() {
    if (lookahead.empty()) {
        currentToken = scanner.getToken();
    } else {
        currentToken = lookahead.front();
        lookahead.pop_front();
    }
}

Token Recogniser::peek(std::size_t n) {
    while (lookahead.size() < n) {
        lookahead.push_back(scanner.getToken());
    }
    return lookahead[n - 1];
}

void Recogniser::syntacticError(std::string message, std::string token) {
    Position pos = currentToken.position;
    reporter.reportError(message, token, pos);
    throw SyntaxError(message);
}


void Recogniser::parseTopLevel() {
    while (currentToken.kind == Token::VOID || currentToken.kind == Token::INT || currentToken.kind == Token::FLOAT) {
        parseTopLevelElem();
    }
}

void Recogniser::parseTopLevelElem() {
    if (peek(2).kind == Token::LPAREN) {
        parseFunDefinition();
    } else {
        parseDeclStmt();
    }
}

void Recogniser::parseTyyDecl() {
    switch (currentToken.kind) {
        case Token::VOID:
            match(Token::VOID);
            break;
        case Token::INT:
            match(Token::INT);
            break;
        case Token::FLOAT:
            match(Token::FLOAT);
            break;
        default:
            syntacticError("Failed Parsing Type:", currentToken.spelling);
    }
}


void Recogniser::parseIdentifier() {
    match(Token::ID);
}


void Recogniser::parseFunDefinition() {
    // TODO
}

void Recogniser::parseDeclStmt() {
    // TODO
}

