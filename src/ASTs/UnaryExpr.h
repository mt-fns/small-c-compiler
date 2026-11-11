#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Operator.h"

// Used for representing a unary expression in the VC grammar.
class UnaryExpr : public Expr {
    public:
        std::unique_ptr<Operator> O;
        std::unique_ptr<Expr> E;

        UnaryExpr(std::unique_ptr<Operator> oAST, std::unique_ptr<Expr> eAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
