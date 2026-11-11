#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Expr.h"

// Used for representing an empty ArrayExprList.
class EmptyArrayExprList : public ASTList<Expr> {
    public:
        EmptyArrayExprList(Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
