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
        currentToken = scanner.getToken();
    } else {
        // TODO: throw a syntax error here once we have the syntax error class
        std::cerr << "EROR IN MATCH" << std::endl;
    }
}

void Recogniser::accept() {
    currentToken = scanner.getToken();
}

void Recogniser::syntacticError(std::string message, std::string token) {
    Position pos = currentToken.position;
    reporter.reportError(message, token, pos);
    throw SyntaxError(message);
}


// PARSE FUCNCTIONS

void Recogniser::parseProgram() {
    while (currentToken.kind != Token::END_OF_FILE) {
        parseType();
        parseIdent();
        if (currentToken.kind == Token::LPAREN) {
            parseFuncDelcRest();
        } else {
            parseVarDeclRest();
        }
    }
}

void Recogniser::parseType() {
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


void Recogniser::parseIdent() {
    if (currentToken.kind == Token::ID) {
        accept();
    } else {
        syntacticError("Failed Parsing Identifier", currentToken.spelling);
    }
}


void Recogniser::parseFuncDelcRest() {

}

void Recogniser::parseVarDeclRest() {

}

