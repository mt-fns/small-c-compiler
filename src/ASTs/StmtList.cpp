#include "ASTs/StmtList.h"

#include <utility>

#include "ASTs/Visitor.h"

StmtList::StmtList(std::unique_ptr<Stmt> head, std::unique_ptr<ASTList<Stmt>> next, Position position) :
    ASTList<Stmt>{std::move(head), std::move(next), position} {}

bool StmtList::isEmpty() const {
    return false;
}

std::any StmtList::visit(Visitor& v, std::any o) {
    return v.visitStmtList(this, o);
}
