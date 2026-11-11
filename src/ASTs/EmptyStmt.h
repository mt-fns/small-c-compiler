#pragma once

#include <any>

#include "Position.h"
#include "ASTs/Stmt.h"

// Used only inside IfStmt
class EmptyStmt : public Stmt {
    public:
        EmptyStmt(Position position);

        std::any visit(Visitor& v, std::any o) override;
};
