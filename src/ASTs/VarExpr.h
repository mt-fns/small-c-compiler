#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Var.h"

class VarExpr : public Expr {
    public:
        std::unique_ptr<Var> V;

        VarExpr(std::unique_ptr<Var> vAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
