#include "ASTs/WhileStmt.h"

#include <utility>

#include "ASTs/Visitor.h"

WhileStmt::WhileStmt(std::unique_ptr<Expr> eAST, std::unique_ptr<Stmt> sAST, Position position) :
    Stmt{position},
    E{std::move(eAST)},
    S{std::move(sAST)} {
    E->parent = this;
    S->parent = this;
}

std::any WhileStmt::visit(Visitor& v, std::any o) {
    return v.visitWhileStmt(this, o);
}
