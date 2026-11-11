#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Arg.h"

// Used for representing an empty list of arguments in a call.
class EmptyArgList : public ASTList<Arg> {
    public:
        EmptyArgList(Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
