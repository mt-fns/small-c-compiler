#include "ASTs/BreakStmt.h"

#include "ASTs/Visitor.h"

BreakStmt::BreakStmt(Position position) : Stmt{position} {}

std::any BreakStmt::visit(Visitor& v, std::any o) {
    return v.visitBreakStmt(this, o);
}
