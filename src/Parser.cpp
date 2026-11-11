#include "Parser.h"
#include "Position.h"
#include "SyntaxError.h"
#include "Token.h"

#include "ASTs/DeclList.h"
#include "ASTs/EmptyDeclList.h"
#include "ASTs/FuncDecl.h"

Parser::Parser(Scanner& scanner, ErrorReporter& reporter) :
    scanner{scanner},
    reporter{reporter},
    currentToken{scanner.getToken()} {}

void Parser::match(int tokenExpected) {
    if (currentToken.kind == tokenExpected) {
        accept();
    } else {
        syntacticError("\"%\" expected here", std::string(Token::spell(tokenExpected)));
    }
}

void Parser::accept() {
    previousTokenPosition = currentToken.position;
    if (lookahead.empty()) {
        currentToken = scanner.getToken();
    } else {
        currentToken = lookahead.front();
        lookahead.pop_front();
    }
}

Token Parser::peek(std::size_t n) {
    while (lookahead.size() < n) {
        lookahead.push_back(scanner.getToken());
    }
    return lookahead[n - 1];
}

void Parser::syntacticError(std::string message, std::string token) {
    Position pos = currentToken.position;
    reporter.reportError(message, token, pos);
    throw SyntaxError(message);
}

void Parser::start(Position& position) {
    position.lineStart = currentToken.position.lineStart;
    position.charStart = currentToken.position.charStart;
}

void Parser::finish(Position& position) {
    position.lineFinish = previousTokenPosition.lineFinish;
    position.charFinish = previousTokenPosition.charFinish;
}

void Parser::copyStart(const Position& from, Position& to) {
    to.lineStart = from.lineStart;
    to.charStart = from.charStart;
}

std::unique_ptr<Operator> Parser::acceptOperator() {
    return nullptr;
}

std::unique_ptr<ASTList<Decl>> Parser::concatDeclLists(std::unique_ptr<ASTList<Decl>> left, std::unique_ptr<ASTList<Decl>> right) {
    if (left->isEmpty()) {
        return right;
    }

    ASTList<Decl>* cur = left.get();
    while (!cur->getNext()->isEmpty()) {
        cur = cur->getNext();
    }

    cur->setNext(std::move(right));
    return left;
}

std::unique_ptr<Program> Parser::parseTopLevel() {
    Position programPos;
    start(programPos);

    std::unique_ptr<ASTList<Decl>> dlAST = std::make_unique<EmptyDeclList>(dummyPos);

    while (currentToken.kind == Token::VOID ||
           currentToken.kind == Token::INT ||
           currentToken.kind == Token::FLOAT) {
        dlAST = concatDeclLists(std::move(dlAST), parseTopLevelElem());
    }

    finish(programPos);
    match(Token::END_OF_FILE);

    return std::make_unique<Program>(std::move(dlAST), programPos);
}

std::unique_ptr<ASTList<Decl>> Parser::parseTopLevelElem() {
    if (peek(2).kind == Token::LPAREN) {
        std::unique_ptr<Decl> fAST = parseFunDefinition();

        Position funPos = fAST->position;

        return std::make_unique<DeclList>(std::move(fAST), std::make_unique<EmptyDeclList>(dummyPos), funPos);
    }

    return parseDeclStmt(true);
}

std::unique_ptr<Decl> Parser::parseFunDefinition() {
    Position funPos;
    start(funPos);

    std::unique_ptr<Type> tAST;
    std::unique_ptr<Ident> iAST;
    std::unique_ptr<ASTList<Decl>> fplAST;
    parseFunSignature(tAST, iAST, fplAST);

    std::unique_ptr<Stmt> cAST = parseCompoundStmt();

    finish(funPos);

    return std::make_unique<FuncDecl>(std::move(tAST), std::move(iAST), std::move(fplAST), std::move(cAST), funPos);
}

void Parser::parseFunSignature(std::unique_ptr<Type>& tAST, std::unique_ptr<Ident>& iAST, std::unique_ptr<ASTList<Decl>>& fplAST) {
}

std::unique_ptr<ASTList<Decl>> Parser::parseDeclStmt(bool isGlobal) {
    return nullptr;
}

std::unique_ptr<ASTList<Decl>> Parser::parseInitList(const Type& tAST, bool isGlobal) {
    return nullptr;
}

std::unique_ptr<Decl> Parser::parseInitDecl(const Type& tAST, bool isGlobal) {
    return nullptr;
}

void Parser::parseDeclarator(std::unique_ptr<Type>& tAST, std::unique_ptr<Ident>& iAST) {
}

std::unique_ptr<Expr> Parser::parseInitialiser() {
    return nullptr;
}

std::unique_ptr<Stmt> Parser::parseCompoundStmt() {
    return nullptr;
}

std::unique_ptr<Stmt> Parser::parseStatement() {
    return nullptr;
}

std::unique_ptr<Stmt> Parser::parseIfStmt() {
    return nullptr;
}

std::unique_ptr<Stmt> Parser::parseForStmt() {
    return nullptr;
}

std::unique_ptr<Stmt> Parser::parseWhileStmt() {
    return nullptr;
}

std::unique_ptr<Stmt> Parser::parseBreakStmt() {
    return nullptr;
}

std::unique_ptr<Stmt> Parser::parseContinueStmt() {
    return nullptr;
}

std::unique_ptr<Stmt> Parser::parseReturnStmt() {
    return nullptr;
}

std::unique_ptr<Stmt> Parser::parseExprStmt() {
    return nullptr;
}

std::unique_ptr<ASTList<Expr>> Parser::parseExprList() {
    return nullptr;
}

std::unique_ptr<ASTList<Arg>> Parser::parseArgList() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parseExpression() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parseAssignExpr() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parseLogOrExpr() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parseLogAndExpr() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parseEqOpExpr() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parseRelopExpr() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parseAddExpr() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parseMultExpr() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parseUnary() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parsePrimary() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parsePrimExpr() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parsePrimIdent() {
    return nullptr;
}

std::unique_ptr<Expr> Parser::parsePrimLiteral() {
    return nullptr;
}

std::unique_ptr<ASTList<Decl>> Parser::parseTtyidPairList() {
    return nullptr;
}

std::unique_ptr<Decl> Parser::parseTtyidPair() {
    return nullptr;
}

std::unique_ptr<Type> Parser::parseTyyDecl() {
    return nullptr;
}

std::unique_ptr<Ident> Parser::parseIdentifier() {
    return nullptr;
}

std::unique_ptr<IntLiteral> Parser::parseIntConst() {
    return nullptr;
}

std::unique_ptr<FloatLiteral> Parser::parseFloatConst() {
    return nullptr;
}

std::unique_ptr<StringLiteral> Parser::parseStrConst() {
    return nullptr;
}
