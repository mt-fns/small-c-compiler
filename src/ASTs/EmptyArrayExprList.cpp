#include "ASTs/EmptyArrayExprList.h"

#include "ASTs/Visitor.h"

EmptyArrayExprList::EmptyArrayExprList(Position position) : ASTList<Expr>{nullptr, nullptr, position} {}

bool EmptyArrayExprList::isEmpty() const {
    return true;
}

std::any EmptyArrayExprList::visit(Visitor& v, std::any o) {
    return v.visitEmptyArrayExprList(this, o);
}
