#include "ASTs/EmptyStmt.h"

#include "ASTs/Visitor.h"

EmptyStmt::EmptyStmt(Position position) : Stmt{position} {}

std::any EmptyStmt::visit(Visitor& v, std::any o) {
    return v.visitEmptyStmt(this, o);
}
