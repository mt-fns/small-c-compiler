#include "ASTs/ParaList.h"

#include <utility>

#include "ASTs/Visitor.h"

ParaList::ParaList(std::unique_ptr<Decl> head, std::unique_ptr<ASTList<Decl>> next, Position position) :
    ASTList<Decl>{std::move(head), std::move(next), position} {}

bool ParaList::isEmpty() const {
    return false;
}

std::any ParaList::visit(Visitor& v, std::any o) {
    return v.visitParaList(this, o);
}
