#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"

// Used for representing an assignment expr defined in the VC grammar.
class AssignExpr : public Expr {
    public:
        std::unique_ptr<Expr> E1;
        std::unique_ptr<Expr> E2;

        AssignExpr(std::unique_ptr<Expr> e1AST, std::unique_ptr<Expr> e2AST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
