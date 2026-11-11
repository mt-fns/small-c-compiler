#include "ASTs/ExprStmt.h"

#include <utility>

#include "ASTs/Visitor.h"

ExprStmt::ExprStmt(std::unique_ptr<Expr> eAST, Position position) :
    Stmt{position},
    E{std::move(eAST)} {
    E->parent = this;
}

std::any ExprStmt::visit(Visitor& v, std::any o) {
    return v.visitExprStmt(this, o);
}
