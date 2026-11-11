#include "ASTs/StringExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

StringExpr::StringExpr(std::unique_ptr<StringLiteral> slAST, Position position) :
    Expr{position},
    SL{std::move(slAST)} {
    SL->parent = this;
}

std::any StringExpr::visit(Visitor& v, std::any o) {
    return v.visitStringExpr(this, o);
}
