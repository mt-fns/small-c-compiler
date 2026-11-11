#pragma once

#include <any>
#include <memory>
#include <string>

#include "Position.h"
#include "ASTs/Expr.h"

// Used for representing an argument in a call.
class Arg : public Expr {
    public:
        std::unique_ptr<Expr> E;

        Arg(std::unique_ptr<Expr> eAST, Position position);

        std::string toString() const override;

        std::any visit(Visitor& v, std::any o) override;
};
