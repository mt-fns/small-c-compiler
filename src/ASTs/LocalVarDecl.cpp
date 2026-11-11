#include "ASTs/LocalVarDecl.h"

#include <utility>

#include "ASTs/Visitor.h"

LocalVarDecl::LocalVarDecl(std::unique_ptr<Type> tAST, std::unique_ptr<Ident> iAST, std::unique_ptr<Expr> eAST, Position position) :
    Decl{position},
    E{std::move(eAST)} {
    T = std::move(tAST);
    I = std::move(iAST);
    T->parent = this;
    I->parent = this;
    E->parent = this;
}

std::string LocalVarDecl::toString() const {
    std::string s = "LocalVarDecl(";
    s += T->toString() + " " + I->toString();
    if (E) {
        s += " = " + E->toString();
    }
    s += ")";
    return s;
}

std::any LocalVarDecl::visit(Visitor& v, std::any o) {
    return v.visitLocalVarDecl(this, o);
}
