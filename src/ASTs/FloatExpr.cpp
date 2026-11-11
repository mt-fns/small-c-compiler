#include "ASTs/FloatExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

FloatExpr::FloatExpr(std::unique_ptr<FloatLiteral> flAST, Position position) :
    Expr{position},
    FL{std::move(flAST)} {
    FL->parent = this;
}

std::any FloatExpr::visit(Visitor& v, std::any o) {
    return v.visitFloatExpr(this, o);
}
