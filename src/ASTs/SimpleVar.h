#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/Ident.h"
#include "ASTs/Var.h"

// Used for representing a scalar or an array variable.
class SimpleVar : public Var {
    public:
        std::unique_ptr<Ident> I;

        SimpleVar(std::unique_ptr<Ident> idAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
