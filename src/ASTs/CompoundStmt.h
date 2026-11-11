#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/ASTList.h"
#include "ASTs/Decl.h"
#include "ASTs/Stmt.h"

class CompoundStmt : public Stmt {
    public:
        std::unique_ptr<ASTList<Decl>> DL;
        std::unique_ptr<ASTList<Stmt>> SL;

        CompoundStmt(std::unique_ptr<ASTList<Decl>> dlAST, std::unique_ptr<ASTList<Stmt>> slAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
