#pragma once

#include <any>

#include "Position.h"
#include "ASTs/Stmt.h"

// Used for representing an empty compound statement, i.e., { }.
class EmptyCompStmt : public Stmt {
    public:
        EmptyCompStmt(Position position);

        std::any visit(Visitor& v, std::any o) override;
};
