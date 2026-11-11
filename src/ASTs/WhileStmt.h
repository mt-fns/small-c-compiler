#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Stmt.h"

class WhileStmt : public Stmt {
    public:
        std::unique_ptr<Expr> E;
        std::unique_ptr<Stmt> S;
        // The two fields below are not currently used
        AST* trueSuccessor = nullptr;
        AST* falseSuccessor = nullptr;

        WhileStmt(std::unique_ptr<Expr> eAST, std::unique_ptr<Stmt> sAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
