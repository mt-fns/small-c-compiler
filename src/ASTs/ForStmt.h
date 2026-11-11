#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Stmt.h"

class ForStmt : public Stmt {
    public:
        std::unique_ptr<Expr> E1;
        std::unique_ptr<Expr> E2;
        std::unique_ptr<Expr> E3;
        std::unique_ptr<Stmt> S;

        ForStmt(std::unique_ptr<Expr> e1AST, std::unique_ptr<Expr> e2AST, std::unique_ptr<Expr> e3AST, std::unique_ptr<Stmt> sAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
