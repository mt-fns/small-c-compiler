#include "ASTs/ArrayExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

ArrayExpr::ArrayExpr(std::unique_ptr<Var> idAST, std::unique_ptr<Expr> indexAST, Position position) :
    Expr{position},
    V{std::move(idAST)},
    E{std::move(indexAST)} {
    V->parent = this;
    E->parent = this;
}

std::any ArrayExpr::visit(Visitor& v, std::any o) {
    return v.visitArrayExpr(this, o);
}
