#include "ASTs/Expr.h"

#include "ASTs/EmptyExpr.h"
#include "ASTs/Type.h"

Expr::Expr(Position position) : AST{position} {}

std::string Expr::toString() const {
    return "Expr: " + (type ? type->toString() : "null");
}

bool Expr::isEmptyExpr() const {
    return dynamic_cast<const EmptyExpr*>(this) != nullptr;
}
