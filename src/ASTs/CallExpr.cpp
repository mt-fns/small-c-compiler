#include "ASTs/CallExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

CallExpr::CallExpr(std::unique_ptr<Ident> id, std::unique_ptr<ASTList<Arg>> aplAST, Position position) :
    Expr{position},
    I{std::move(id)},
    AL{std::move(aplAST)} {
    I->parent = this;
    AL->parent = this;
}

std::any CallExpr::visit(Visitor& v, std::any o) {
    return v.visitCallExpr(this, o);
}
