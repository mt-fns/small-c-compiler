#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Stmt.h"

class ReturnStmt : public Stmt {
    public:
        std::unique_ptr<Expr> E;

        ReturnStmt(std::unique_ptr<Expr> eAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
