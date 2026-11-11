#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Arg.h"
#include "ASTs/Expr.h"
#include "ASTs/Ident.h"

// Used for representing a call expression.
class CallExpr : public Expr {
    public:
        std::unique_ptr<Ident> I;
        std::unique_ptr<ASTList<Arg>> AL;

        CallExpr(std::unique_ptr<Ident> id, std::unique_ptr<ASTList<Arg>> aplAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
