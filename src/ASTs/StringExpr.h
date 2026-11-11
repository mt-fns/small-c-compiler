#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/StringLiteral.h"

class StringExpr : public Expr {
    public:
        std::unique_ptr<StringLiteral> SL;

        StringExpr(std::unique_ptr<StringLiteral> slAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
