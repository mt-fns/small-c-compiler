#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Decl.h"

// Represents a list of declarations, including function declarations,
// global variable declarations, and local variable declarations.
//
// A Program consists of a DeclList containing function and global
// variable declarations.
//
// Each function's body, represented by a compound statement (or block),
// is split into two lists: a DeclList for its local variable declarations
// and a StmtList for its statements.
//
// Its sibling class, `EmptyDeclList`, represents an empty `DeclList`.
class DeclList : public ASTList<Decl> {
    public:
        DeclList(std::unique_ptr<Decl> head, std::unique_ptr<ASTList<Decl>> next, Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
