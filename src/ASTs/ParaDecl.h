#pragma once

#include <any>
#include <memory>
#include <string>

#include "Position.h"
#include "ASTs/Decl.h"
#include "ASTs/Ident.h"
#include "ASTs/Type.h"

class ParaDecl : public Decl {
    public:
        ParaDecl(std::unique_ptr<Type> tAST, std::unique_ptr<Ident> idAST, Position position);

        std::string toString() const override;

        std::any visit(Visitor& v, std::any o) override;
};
