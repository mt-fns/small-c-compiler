#include "ASTs/UnaryExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

UnaryExpr::UnaryExpr(std::unique_ptr<Operator> oAST, std::unique_ptr<Expr> eAST, Position position) :
    Expr{position},
    O{std::move(oAST)},
    E{std::move(eAST)} {
    O->parent = this;
    E->parent = this;
}

std::any UnaryExpr::visit(Visitor& v, std::any o) {
    return v.visitUnaryExpr(this, o);
}
