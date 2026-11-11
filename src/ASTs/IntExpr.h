#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/IntLiteral.h"

// Used for representing an expression that consists of a single IntLiteral.
class IntExpr : public Expr {
    public:
        std::unique_ptr<IntLiteral> IL;

        IntExpr(std::unique_ptr<IntLiteral> ilAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
