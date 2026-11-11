#pragma once

#include <any>

#include "Position.h"
#include "ASTs/Stmt.h"

class ContinueStmt : public Stmt {
    public:
        ContinueStmt(Position position);

        std::any visit(Visitor& v, std::any o) override;
};
