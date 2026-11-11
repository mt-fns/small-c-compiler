#include "ASTs/IfStmt.h"

#include <utility>

#include "ASTs/EmptyStmt.h"
#include "ASTs/Visitor.h"

IfStmt::IfStmt(std::unique_ptr<Expr> eAST, std::unique_ptr<Stmt> sAST, Position position) :
    IfStmt{std::move(eAST), std::move(sAST), std::make_unique<EmptyStmt>(Position()), position} {}

IfStmt::IfStmt(std::unique_ptr<Expr> eAST, std::unique_ptr<Stmt> s1AST, std::unique_ptr<Stmt> s2AST, Position position) :
    Stmt{position},
    E{std::move(eAST)},
    S1{std::move(s1AST)},
    S2{std::move(s2AST)} {
    E->parent = this;
    S1->parent = this;
    S2->parent = this;
}

std::any IfStmt::visit(Visitor& v, std::any o) {
    return v.visitIfStmt(this, o);
}
