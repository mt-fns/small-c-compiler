#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Stmt.h"

// Its sibling class, `EmptyStmtList`, represents an empty `StmtList`.
class StmtList : public ASTList<Stmt> {
    public:
        StmtList(std::unique_ptr<Stmt> head, std::unique_ptr<ASTList<Stmt>> next, Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
