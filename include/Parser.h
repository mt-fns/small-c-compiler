#pragma once

#include <cstddef>
#include <deque>
#include <memory>
#include <string>

#include "ErrorReporter.h"
#include "Position.h"
#include "Scanner.h"
#include "Token.h"

#include "ASTs/ASTList.h"
#include "ASTs/Arg.h"
#include "ASTs/Decl.h"
#include "ASTs/Expr.h"
#include "ASTs/FloatLiteral.h"
#include "ASTs/Ident.h"
#include "ASTs/IntLiteral.h"
#include "ASTs/Operator.h"
#include "ASTs/Program.h"
#include "ASTs/Stmt.h"
#include "ASTs/StringLiteral.h"
#include "ASTs/Type.h"

class Parser {
    public:
        Parser(Scanner& scanner, ErrorReporter& reporter);

        std::unique_ptr<Program> parseTopLevel();
        std::unique_ptr<ASTList<Decl>> parseTopLevelElem();

        std::unique_ptr<Decl> parseFunDefinition();
        void parseFunSignature(std::unique_ptr<Type>& tAST, std::unique_ptr<Ident>& iAST, std::unique_ptr<ASTList<Decl>>& fplAST);
        std::unique_ptr<Stmt> parseCompoundStmt();

        std::unique_ptr<ASTList<Decl>> parseDeclStmt(bool isGlobal);
        std::unique_ptr<ASTList<Decl>> parseInitList(const Type& tAST, bool isGlobal);
        std::unique_ptr<Decl> parseInitDecl(const Type& tAST, bool isGlobal);
        void parseDeclarator(std::unique_ptr<Type>& tAST, std::unique_ptr<Ident>& iAST);
        std::unique_ptr<Expr> parseInitialiser();

        std::unique_ptr<Type> parseTyyDecl();
        std::unique_ptr<Ident> parseIdentifier();
        std::unique_ptr<ASTList<Decl>> parseTtyidPairList();
        std::unique_ptr<Decl> parseTtyidPair();

        std::unique_ptr<IntLiteral> parseIntConst();
        std::unique_ptr<FloatLiteral> parseFloatConst();
        std::unique_ptr<StringLiteral> parseStrConst();

        std::unique_ptr<ASTList<Expr>> parseExprList();
        std::unique_ptr<ASTList<Arg>> parseArgList();
        std::unique_ptr<Expr> parseExpression();
        std::unique_ptr<Expr> parseAssignExpr();

        std::unique_ptr<Expr> parseLogOrExpr();
        std::unique_ptr<Expr> parseLogAndExpr();
        std::unique_ptr<Expr> parseEqOpExpr();
        std::unique_ptr<Expr> parseRelopExpr();
        std::unique_ptr<Expr> parseAddExpr();
        std::unique_ptr<Expr> parseMultExpr();

        std::unique_ptr<Expr> parseUnary();

        std::unique_ptr<Stmt> parseStatement();
        std::unique_ptr<Stmt> parseIfStmt();
        std::unique_ptr<Stmt> parseForStmt();
        std::unique_ptr<Stmt> parseWhileStmt();
        std::unique_ptr<Stmt> parseBreakStmt();
        std::unique_ptr<Stmt> parseContinueStmt();
        std::unique_ptr<Stmt> parseReturnStmt();
        std::unique_ptr<Stmt> parseExprStmt();

        std::unique_ptr<Expr> parsePrimary();
        std::unique_ptr<Expr> parsePrimExpr();
        std::unique_ptr<Expr> parsePrimIdent();
        std::unique_ptr<Expr> parsePrimLiteral();

    private:
        std::unique_ptr<Operator> acceptOperator();

        std::unique_ptr<ASTList<Decl>> concatDeclLists(std::unique_ptr<ASTList<Decl>> left, std::unique_ptr<ASTList<Decl>> right);

        void match(int tokenExpected);

        void accept();

        Token peek(std::size_t n);

        [[noreturn]] void syntacticError(std::string message, std::string token);

        void start(Position& position);

        void finish(Position& position);

        void copyStart(const Position& from, Position& to);

        Scanner& scanner;
        ErrorReporter& reporter;
        Token currentToken;
        Position previousTokenPosition;
        Position dummyPos;

        std::deque<Token> lookahead;
};
