#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Decl.h"

// Used for representing an empty list of parameters in a function declaration.
class EmptyParaList : public ASTList<Decl> {
    public:
        EmptyParaList(Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
