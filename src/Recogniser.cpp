#include "Recogniser.h"
#include "Position.h"
#include "Source.h"
#include "SyntaxError.h"
#include "Token.h"
#include <exception>

Recogniser::Recogniser(Scanner& scanner, ErrorReporter& reporter) :
    scanner{scanner},
    reporter{reporter},
    currentToken{scanner.getToken()} {}

void Recogniser::match(int tokenExpected) {
    if (currentToken.kind == tokenExpected) {
        accept();
    } else {
        syntacticError("michael skibidi", currentToken.spelling);
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

void Recogniser::parseExprList() {
    parseExpression();

    while (currentToken.kind == Token::COMMA) {
        match(Token::COMMA);
        parseExpression();
    }
}

void Recogniser::parseExpression() {
    parseAssignExpr();
}

void Recogniser::parseAssignExpr() {
    parseLogOrExpr();
    if (currentToken.kind == Token::COMMA) {
        match(Token::COMMA);
        parseAssignExpr();
    }
}


void Recogniser::parseLogOrExpr() {
    parseLogAndExpr();
    while (currentToken.kind == Token::OROR) {
        match(Token::OROR);
        parseLogAndExpr();
    }
}

void Recogniser::parseFunDefinition() {
    parseFunSignature();
    parseCompoundStmt();
}

void Recogniser::parseFunSignature() {
    parseTyyDecl();
    parseIdentifier();
    match(Token::LPAREN);
    if (currentToken.kind == Token::VOID || 
        currentToken.kind == Token::INT || 
        currentToken.kind == Token::FLOAT) {
        parseTtyidPairList();
    }
    match(Token::RPAREN);
}

void Recogniser::parseTtyidPairList() {
    parseTtyidPair();
    while (currentToken.kind == Token::COMMA) {
        match(Token::COMMA);
        parseTtyidPair();
    }
}

void Recogniser::parseTtyidPair() {
    parseTyyDecl();
    parseDeclarator();
}

void Recogniser::parseDeclarator() {
    parseIdentifier();
    if (currentToken.kind == Token::LBRACKET) {
        match(Token::LBRACKET);
        if (currentToken.kind == Token::INTLITERAL) {
            parseIntConst();
        }
        match(Token::RBRACKET);
    }
}

void Recogniser::parseIntConst() {
    match(Token::INTLITERAL);
}

void Recogniser::parseCompoundStmt() {
    match(Token::LCURLY);
    while (currentToken.kind == Token::VOID || 
           currentToken.kind == Token::INT || 
           currentToken.kind == Token::FLOAT) {
        parseDeclStmt();
    }
    parseStatement();
    match(Token::RCURLY);
}

void Recogniser::parseStatement() {
    parseCompoundStmt();
    parseIfStmt();
    parseForStmt();
    parseWhileStmt();
    parseBreakStmt();
    parseContinueStmt();
    parseReturnStmt();
    parseExprStmt();
}

void Recogniser::parseIfStmt() {
    if (currentToken.kind != Token::IF) {
        return;
    }
    match(Token::LPAREN);
    parseExpression();
    match(Token::RPAREN);
    parseStatement();
    if (currentToken.kind == Token::ELSE) {
        parseStatement();
    }
}

void Recogniser::parseForStmt() {
    if (currentToken.kind != Token::FOR) {
        return;
    }
    match(Token::LPAREN);
    if (currentToken.kind == Token::LBRACKET) {
        match(Token::LBRACKET);
        parseExpression();
        match(Token::RBRACKET);
        match(Token::SEMICOLON);

        if (currentToken.kind == Token::LBRACKET) {
            match(Token::LBRACKET);
            parseExpression();
            match(Token::RBRACKET);
            match(Token::SEMICOLON);

            if (currentToken.kind == Token::LBRACKET) {
                match(Token::LBRACKET);
                parseExpression();
                match(Token::RBRACKET);

            }
        }
    }
    match(Token::RPAREN);
    parseStatement();

}

void Recogniser::parseWhileStmt() {
    if (currentToken.kind != Token::WHILE) {
        return;
    }
    match(Token::LPAREN);
    parseExpression();
    match(Token::RPAREN);
    parseStatement();
}

void Recogniser::parseBreakStmt() {
    if (currentToken.kind != Token::BREAK) {
        return;
    }
    match(Token::SEMICOLON);
}

void Recogniser::parseLogAndExpr() {
    parseEqOpExpr();

    while (currentToken.kind == Token::ANDAND) {
        match(Token::ANDAND);
        parseEqOpExpr();
    }
}


void Recogniser::parseEqOpExpr() {
    parseRelopExpr();

    while (currentToken.kind == Token::EQEQ || currentToken.kind == Token::NOTEQ) {
        currentToken.kind == Token::EQEQ ? match(Token::EQEQ) : match(Token::NOTEQ);
        parseRelopExpr();
    }
}

void Recogniser::parseRelopExpr() {
    parseAddExpr();
    while (currentToken.kind == Token::LT || currentToken.kind == Token::LTEQ || currentToken.kind == Token::GT || currentToken.kind == Token::GTEQ) {
        match(currentToken.kind);
        parseAddExpr();
    }
}

void Recogniser::parseAddExpr() {
    parseMultExpr();

    while (currentToken.kind == Token::PLUS || currentToken.kind == Token::MINUS) {
        match(currentToken.kind);
        parseMultExpr();
    }
}

void Recogniser::parseMultExpr() {
    parseUnary();
    while (currentToken.kind == Token::MULT || currentToken.kind == Token::DIV) {
        match(currentToken.kind);
        parseUnary();
    }
}
void Recogniser::parseDeclStmt() {
    parseTyyDecl();
    parseInitList();
    match(Token::SEMICOLON);
}

void Recogniser::parseInitList() {
    parseInitDecl();

    while (currentToken.kind == Token::COMMA) {
        match(Token::COMMA);
        parseInitDecl();
    }
}

void Recogniser::parseInitDecl() {
    // parseDeclarator();

    if (currentToken.kind == Token::EQ) {
        match(Token::EQ);
        parseInitialiser();
    }
}
