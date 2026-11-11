#include "ASTs/EmptyStmtList.h"

#include "ASTs/Visitor.h"

EmptyStmtList::EmptyStmtList(Position position) : ASTList<Stmt>{nullptr, nullptr, position} {}

bool EmptyStmtList::isEmpty() const {
    return true;
}

std::any EmptyStmtList::visit(Visitor& v, std::any o) {
    return v.visitEmptyStmtList(this, o);
}
