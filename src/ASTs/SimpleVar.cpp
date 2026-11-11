#include "ASTs/SimpleVar.h"

#include <utility>

#include "ASTs/Visitor.h"

SimpleVar::SimpleVar(std::unique_ptr<Ident> idAST, Position position) :
    Var{position},
    I{std::move(idAST)} {
    I->parent = this;
}

std::any SimpleVar::visit(Visitor& v, std::any o) {
    return v.visitSimpleVar(this, o);
}
