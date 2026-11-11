#include "ASTs/EmptyDeclList.h"

#include "ASTs/Visitor.h"

EmptyDeclList::EmptyDeclList(Position position) : ASTList<Decl>{nullptr, nullptr, position} {}

bool EmptyDeclList::isEmpty() const {
    return true;
}

std::any EmptyDeclList::visit(Visitor& v, std::any o) {
    return v.visitEmptyDeclList(this, o);
}
