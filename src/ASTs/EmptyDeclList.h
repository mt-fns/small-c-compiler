#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Decl.h"

// Used for representing an empty DeclList.
class EmptyDeclList : public ASTList<Decl> {
    public:
        EmptyDeclList(Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
