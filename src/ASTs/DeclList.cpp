#include "ASTs/DeclList.h"

#include <utility>

#include "ASTs/Visitor.h"

DeclList::DeclList(std::unique_ptr<Decl> head, std::unique_ptr<ASTList<Decl>> next, Position position) :
    ASTList<Decl>{std::move(head), std::move(next), position} {}

bool DeclList::isEmpty() const {
    return false;
}

std::any DeclList::visit(Visitor& v, std::any o) {
    return v.visitDeclList(this, o);
}
