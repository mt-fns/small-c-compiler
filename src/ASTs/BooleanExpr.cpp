#include "ASTs/BooleanExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

BooleanExpr::BooleanExpr(std::unique_ptr<BooleanLiteral> blAST, Position position) :
    Expr{position},
    BL{std::move(blAST)} {
    BL->parent = this;
}

std::any BooleanExpr::visit(Visitor& v, std::any o) {
    return v.visitBooleanExpr(this, o);
}
