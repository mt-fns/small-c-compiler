#include "ASTs/ParaDecl.h"

#include <utility>

#include "ASTs/Visitor.h"

ParaDecl::ParaDecl(std::unique_ptr<Type> tAST, std::unique_ptr<Ident> idAST, Position position) :
    Decl{position} {
    T = std::move(tAST);
    I = std::move(idAST);
    T->parent = this;
    I->parent = this;
}

std::string ParaDecl::toString() const {
    return "ParaDecl(" + T->toString() + " " + I->toString() + ")";
}

std::any ParaDecl::visit(Visitor& v, std::any o) {
    return v.visitParaDecl(this, o);
}
