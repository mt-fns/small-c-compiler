#include "ASTs/ForStmt.h"

#include <utility>

#include "ASTs/Visitor.h"

ForStmt::ForStmt(std::unique_ptr<Expr> e1AST, std::unique_ptr<Expr> e2AST, std::unique_ptr<Expr> e3AST, std::unique_ptr<Stmt> sAST, Position position) :
    Stmt{position},
    E1{std::move(e1AST)},
    E2{std::move(e2AST)},
    E3{std::move(e3AST)},
    S{std::move(sAST)} {
    E1->parent = this;
    E2->parent = this;
    E3->parent = this;
    S->parent = this;
}

std::any ForStmt::visit(Visitor& v, std::any o) {
    return v.visitForStmt(this, o);
}
