#include "ASTs/CompoundStmt.h"

#include <utility>

#include "ASTs/Visitor.h"

CompoundStmt::CompoundStmt(std::unique_ptr<ASTList<Decl>> dlAST, std::unique_ptr<ASTList<Stmt>> slAST, Position position) :
    Stmt{position},
    DL{std::move(dlAST)},
    SL{std::move(slAST)} {
    DL->parent = this;
    SL->parent = this;
}

std::any CompoundStmt::visit(Visitor& v, std::any o) {
    return v.visitCompoundStmt(this, o);
}
