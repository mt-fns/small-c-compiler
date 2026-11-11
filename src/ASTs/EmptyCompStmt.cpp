#include "ASTs/EmptyCompStmt.h"

#include "ASTs/Visitor.h"

EmptyCompStmt::EmptyCompStmt(Position position) : Stmt{position} {}

std::any EmptyCompStmt::visit(Visitor& v, std::any o) {
    return v.visitEmptyCompStmt(this, o);
}
