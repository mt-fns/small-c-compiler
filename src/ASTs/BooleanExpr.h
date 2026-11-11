#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/BooleanLiteral.h"
#include "ASTs/Expr.h"

// Used for representing a Boolean expression consisting of a Boolean literal.
class BooleanExpr : public Expr {
    public:
        std::unique_ptr<BooleanLiteral> BL;
        // The two fields below are not currently used
        AST* trueSuccessor = nullptr;
        AST* falseSuccessor = nullptr;

        BooleanExpr(std::unique_ptr<BooleanLiteral> blAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
