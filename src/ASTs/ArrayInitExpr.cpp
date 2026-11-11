#include "ASTs/ArrayInitExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

ArrayInitExpr::ArrayInitExpr(std::unique_ptr<ASTList<Expr>> ilAST, Position position) :
    Expr{position},
    IL{std::move(ilAST)} {
    IL->parent = this;
}

std::any ArrayInitExpr::visit(Visitor& v, std::any o) {
    return v.visitArrayInitExpr(this, o);
}
