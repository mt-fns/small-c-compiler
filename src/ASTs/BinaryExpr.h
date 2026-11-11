#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Operator.h"

// Used for representing a binary expression defined in the VC grammar.
class BinaryExpr : public Expr {
    public:
        std::unique_ptr<Expr> E1;
        std::unique_ptr<Expr> E2;
        std::unique_ptr<Operator> O;

        BinaryExpr(std::unique_ptr<Expr> e1AST, std::unique_ptr<Operator> oAST, std::unique_ptr<Expr> e2AST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
