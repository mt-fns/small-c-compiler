#pragma once

#include <any>

#include "Position.h"
#include "ASTs/Expr.h"

// Used for representing an expression that is not explicitly given.
class EmptyExpr : public Expr {
    public:
        EmptyExpr(Position position);

        std::any visit(Visitor& v, std::any o) override;
};
