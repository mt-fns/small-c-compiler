#include "ASTs/ArrayExprList.h"

#include <utility>

#include "ASTs/Visitor.h"

ArrayExprList::ArrayExprList(std::unique_ptr<Expr> head, std::unique_ptr<ASTList<Expr>> next, Position position) :
    ASTList<Expr>{std::move(head), std::move(next), position} {}

bool ArrayExprList::isEmpty() const {
    return false;
}

std::any ArrayExprList::visit(Visitor& v, std::any o) {
    return v.visitArrayExprList(this, o);
}
