#include "ASTs/ArgList.h"

#include <utility>

#include "ASTs/Visitor.h"

ArgList::ArgList(std::unique_ptr<Arg> head, std::unique_ptr<ASTList<Arg>> next, Position position) :
    ASTList<Arg>{std::move(head), std::move(next), position} {}

bool ArgList::isEmpty() const {
    return false;
}

std::any ArgList::visit(Visitor& v, std::any o) {
    return v.visitArgList(this, o);
}
