#pragma once

#include <any>
#include <memory>
#include <string>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Decl.h"
#include "ASTs/Ident.h"
#include "ASTs/Stmt.h"
#include "ASTs/Type.h"

class FuncDecl : public Decl {
    public:
        std::unique_ptr<ASTList<Decl>> PL;
        std::unique_ptr<Stmt> S;

        FuncDecl(std::unique_ptr<Type> tAST, std::unique_ptr<Ident> idAST, std::unique_ptr<ASTList<Decl>> fplAST, std::unique_ptr<Stmt> cAST, Position position);

        std::string toString() const override;

        std::any visit(Visitor& v, std::any o) override;
};
