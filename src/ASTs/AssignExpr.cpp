#include "ASTs/AssignExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

AssignExpr::AssignExpr(std::unique_ptr<Expr> e1AST, std::unique_ptr<Expr> e2AST, Position position) :
    Expr{position},
    E1{std::move(e1AST)},
    E2{std::move(e2AST)} {
    E1->parent = this;
    E2->parent = this;
}

std::any AssignExpr::visit(Visitor& v, std::any o) {
    return v.visitAssignExpr(this, o);
}
