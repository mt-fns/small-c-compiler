#include "ASTs/Stmt.h"

#include "ASTs/EmptyCompStmt.h"
#include "ASTs/EmptyStmt.h"

Stmt::Stmt(Position position) : AST{position} {}

bool Stmt::isEmptyStmt() const {
    return dynamic_cast<const EmptyStmt*>(this) != nullptr;
}

bool Stmt::isEmptyCompStmt() const {
    return dynamic_cast<const EmptyCompStmt*>(this) != nullptr;
}
