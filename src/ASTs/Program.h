#pragma once

#include <any>
#include <memory>

#include "Position.h"
#include "ASTs/AST.h"
#include "ASTs/ASTList.h"
#include "ASTs/Decl.h"

class Program : public AST {
    public:
        std::unique_ptr<ASTList<Decl>> FL;

        Program(std::unique_ptr<ASTList<Decl>> dlAST, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
