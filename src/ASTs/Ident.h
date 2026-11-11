#pragma once

#include <any>
#include <string>

#include "Position.h"
#include "ASTs/Terminal.h"

class Ident : public Terminal {
    public:
        AST* decl = nullptr;  // the declaration this identifier refers to; not owned by this node

        Ident(std::string value, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
