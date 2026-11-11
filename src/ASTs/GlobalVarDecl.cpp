#include "ASTs/GlobalVarDecl.h"

#include <utility>

#include "ASTs/Visitor.h"

GlobalVarDecl::GlobalVarDecl(std::unique_ptr<Type> tAST, std::unique_ptr<Ident> iAST, std::unique_ptr<Expr> eAST, Position position) :
    Decl{position},
    E{std::move(eAST)} {
    T = std::move(tAST);
    I = std::move(iAST);
    T->parent = this;
    I->parent = this;
    E->parent = this;
}

std::string GlobalVarDecl::toString() const {
    std::string s = "GlobalVarDecl(";
    s += T->toString() + " " + I->toString();
    if (E) {
        s += " = " + E->toString();
    }
    s += ")";
    return s;
}

std::any GlobalVarDecl::visit(Visitor& v, std::any o) {
    return v.visitGlobalVarDecl(this, o);
}
