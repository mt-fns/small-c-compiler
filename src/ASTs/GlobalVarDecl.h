#pragma once

#include <any>
#include <memory>
#include <string>

#include "Position.h"
#include "ASTs/Decl.h"
#include "ASTs/Expr.h"
#include "ASTs/Ident.h"
#include "ASTs/Type.h"

class GlobalVarDecl : public Decl {
    public:
        std::unique_ptr<Expr> E;

        GlobalVarDecl(std::unique_ptr<Type> tAST, std::unique_ptr<Ident> iAST, std::unique_ptr<Expr> eAST, Position position);

        std::string toString() const override;

        std::any visit(Visitor& v, std::any o) override;
};
