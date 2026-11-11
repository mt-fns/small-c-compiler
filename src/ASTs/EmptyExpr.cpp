#include "ASTs/EmptyExpr.h"

#include "ASTs/Visitor.h"

EmptyExpr::EmptyExpr(Position position) : Expr{position} {}

std::any EmptyExpr::visit(Visitor& v, std::any o) {
    return v.visitEmptyExpr(this, o);
}
