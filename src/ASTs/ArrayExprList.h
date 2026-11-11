#pragma once

#include <any>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Expr.h"

// Used for representing the list of expressions defined
// by the following productions in the VC grammar:
//
// initialiser         -> expr
//                      |  "{" expr ( "," expr )* "}"
//
// Given the following array declaration:
//
// int a[] = {3, 4, 5};
//
// An ArrayExprList will be created to represent the list of three expressions,
// 3, 4 and 5, given inside { and }.
//
// Its sibling class, `EmptyArrayExprList`, represents an empty `ArrayExprList`.
class ArrayExprList : public ASTList<Expr> {
    public:
        int index = 0;  // array index where this element should go

        ArrayExprList(std::unique_ptr<Expr> head, std::unique_ptr<ASTList<Expr>> next, Position position);

        bool isEmpty() const override;

        std::any visit(Visitor& v, std::any o) override;
};
