#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Stmt.h"

// Used for representing an expression statement defined in the VC grammar.
class ExprStmt : public Stmt {
    public:
        std::unique_ptr<Expr> E;

        ExprStmt(std::unique_ptr<Expr> eAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
