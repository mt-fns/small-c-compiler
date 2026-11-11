#pragma once

#include <memory>
#include <string>

#include "Position.h"
#include "ASTs/AST.h"
#include "ASTs/Ident.h"
#include "ASTs/Type.h"

class Decl : public AST {
    public:
        std::unique_ptr<Type> T;
        std::unique_ptr<Ident> I;

        // the index of this variable or formal parameter
        // See page 72, the JVM spec, 2nd edition.
        int index = 0;

        Decl(Position position);

        bool isFuncDecl() const;
        bool isGlobalVarDecl() const;
        bool isLocalVarDecl() const;
        bool isParaDecl() const;

        std::string toString() const override;
};
