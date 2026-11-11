#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Decl.h"

// Used for representing a non-empty list of parameters in a function declaration.
//
// Its sibling class, `EmptyParaList`, represents an empty `ParaList`.
class ParaList : public ASTList<Decl> {
    public:
        ParaList(std::unique_ptr<Decl> head, std::unique_ptr<ASTList<Decl>> next, Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
