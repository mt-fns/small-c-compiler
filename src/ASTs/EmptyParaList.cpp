#include "ASTs/EmptyParaList.h"

#include "ASTs/Visitor.h"

EmptyParaList::EmptyParaList(Position position) : ASTList<Decl>{nullptr, nullptr, position} {}

bool EmptyParaList::isEmpty() const {
    return true;
}

std::any EmptyParaList::visit(Visitor& v, std::any o) {
    return v.visitEmptyParaList(this, o);
}
