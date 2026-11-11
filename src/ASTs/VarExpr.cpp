#include "ASTs/VarExpr.h"

#include <utility>

#include "ASTs/Visitor.h"

VarExpr::VarExpr(std::unique_ptr<Var> vAST, Position position) :
    Expr{position},
    V{std::move(vAST)} {
    V->parent = this;
}

std::any VarExpr::visit(Visitor& v, std::any o) {
    return v.visitVarExpr(this, o);
}
