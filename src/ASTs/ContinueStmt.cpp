#include "ASTs/ContinueStmt.h"

#include "ASTs/Visitor.h"

ContinueStmt::ContinueStmt(Position position) : Stmt{position} {}

std::any ContinueStmt::visit(Visitor& v, std::any o) {
    return v.visitContinueStmt(this, o);
}
