#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/FloatLiteral.h"

// Used for representing an expression that consists of a single FloatLiteral.
class FloatExpr : public Expr {
    public:
        std::unique_ptr<FloatLiteral> FL;

        FloatExpr(std::unique_ptr<FloatLiteral> flAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
