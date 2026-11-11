#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Var.h"

// Used for representing an array expression.
class ArrayExpr : public Expr {
    public:
        std::unique_ptr<Var> V;
        std::unique_ptr<Expr> E;  // index of array var

        ArrayExpr(std::unique_ptr<Var> idAST, std::unique_ptr<Expr> indexAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
