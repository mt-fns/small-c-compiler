#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Expr.h"

// Used for representing an expression provided for initialising an array
// variable according to the following production in the VC grammar:
//
// initialiser         -> "{" expr ( "," expr )* "}"
//
// Given the following two declarations, where arrays a and b are declared:
//
// int a[2] = {1, 2};
// int b = {3,4,5};
//
// {1, 2} and {3, 4, 5} are two array initialisation expressions, i.e., ArrayInitExprs.
//
// When an ArrayInitExpr node is drawn, ArrayInitExpr is abbreviated to ArrInitExpr.
//
// See also ArrayExprList.
class ArrayInitExpr : public Expr {
    public:
        std::unique_ptr<ASTList<Expr>> IL;

        ArrayInitExpr(std::unique_ptr<ASTList<Expr>> ilAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
