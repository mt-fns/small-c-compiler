#include "ASTs/BinaryExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

BinaryExpr::BinaryExpr(std::unique_ptr<Expr> e1AST, std::unique_ptr<Operator> oAST, std::unique_ptr<Expr> e2AST, Position position) :
    Expr{position},
    E1{std::move(e1AST)},
    E2{std::move(e2AST)},
    O{std::move(oAST)} {
    E1->parent = this;
    O->parent = this;
    E2->parent = this;
}

std::any BinaryExpr::visit(Visitor& v, std::any o) {
    return v.visitBinaryExpr(this, o);
}
