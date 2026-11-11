#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Stmt.h"

class IfStmt : public Stmt {
    public:
        std::unique_ptr<Expr> E;
        std::unique_ptr<Stmt> S1;
        std::unique_ptr<Stmt> S2;
        // The two fields below are not currently used
        AST* trueSuccessor = nullptr;
        AST* falseSuccessor = nullptr;

        // an if without an else gets an EmptyStmt as its else branch
        IfStmt(std::unique_ptr<Expr> eAST, std::unique_ptr<Stmt> sAST, Position position);

        IfStmt(std::unique_ptr<Expr> eAST, std::unique_ptr<Stmt> s1AST, std::unique_ptr<Stmt> s2AST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
