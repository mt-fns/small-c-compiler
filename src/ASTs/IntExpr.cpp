#include "ASTs/IntExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

IntExpr::IntExpr(std::unique_ptr<IntLiteral> ilAST, Position position) :
    Expr{position},
    IL{std::move(ilAST)} {
    IL->parent = this;
}

std::any IntExpr::visit(Visitor& v, std::any o) {
    return v.visitIntExpr(this, o);
}
