#pragma once

#include <any>

#include "Position.h"
#include "ASTs/Stmt.h"

class BreakStmt : public Stmt {
    public:
        BreakStmt(Position position);

        std::any visit(Visitor& v, std::any o) override;
};
