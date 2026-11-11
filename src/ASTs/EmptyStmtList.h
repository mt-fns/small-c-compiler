#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Stmt.h"

class EmptyStmtList : public ASTList<Stmt> {
    public:
        EmptyStmtList(Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
