#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Arg.h"

// Used for representing a non-empty list of arguments in a call.
//
// Its sibling class, `EmptyArgList`, represents an empty `ArgList`.
class ArgList : public ASTList<Arg> {
    public:
        ArgList(std::unique_ptr<Arg> head, std::unique_ptr<ASTList<Arg>> next, Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
