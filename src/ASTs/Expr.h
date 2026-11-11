#pragma once

#include <string>

#include "Position.h"
#include "ASTs/AST.h"

class Type;

class Expr : public AST {
    public:
        // set by the type checker; not owned by this node
        Type* type = nullptr;

        Expr(Position position);

        std::string toString() const override;

        bool isEmptyExpr() const;
};
