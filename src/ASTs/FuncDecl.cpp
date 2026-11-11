#include "ASTs/FuncDecl.h"

#include <utility>

#include "ASTs/Visitor.h"

FuncDecl::FuncDecl(std::unique_ptr<Type> tAST, std::unique_ptr<Ident> idAST, std::unique_ptr<ASTList<Decl>> fplAST, std::unique_ptr<Stmt> cAST, Position position) :
    Decl{position},
    PL{std::move(fplAST)},
    S{std::move(cAST)} {
    T = std::move(tAST);
    I = std::move(idAST);
    T->parent = this;
    I->parent = this;
    PL->parent = this;
    S->parent = this;
}

std::string FuncDecl::toString() const {
    std::string s = "FuncDecl(";
    s += T->toString() + " ";  // return type
    s += I->toString();        // function name

    s += "(";
    if (PL && !PL->isEmpty()) {
        std::vector<Decl*> params = PL->toList();
        for (std::size_t i = 0; i < params.size(); i++) {
            s += params[i]->toString();
            if (i < params.size() - 1) {
                s += ", ";
            }
        }
    }
    s += ")";

    s += ")";
    return s;
}

std::any FuncDecl::visit(Visitor& v, std::any o) {
    return v.visitFuncDecl(this, o);
}
