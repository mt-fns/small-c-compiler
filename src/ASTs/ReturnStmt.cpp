#include "ASTs/ReturnStmt.h"

#include <utility>

#include "ASTs/Visitor.h"

ReturnStmt::ReturnStmt(std::unique_ptr<Expr> eAST, Position position) :
    Stmt{position},
    E{std::move(eAST)} {
    E->parent = this;
}

std::any ReturnStmt::visit(Visitor& v, std::any o) {
    return v.visitReturnStmt(this, o);
}
