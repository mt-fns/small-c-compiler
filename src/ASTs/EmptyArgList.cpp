#include "ASTs/EmptyArgList.h"

#include "ASTs/Visitor.h"

EmptyArgList::EmptyArgList(Position position) : ASTList<Arg>{nullptr, nullptr, position} {}

bool EmptyArgList::isEmpty() const {
    return true;
}

std::any EmptyArgList::visit(Visitor& v, std::any o) {
    return v.visitEmptyArgList(this, o);
}
