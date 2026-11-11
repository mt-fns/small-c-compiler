#pragma once

#include "Position.h"
#include "ASTs/AST.h"

class Stmt : public AST {
    public:
        Stmt(Position position);

        bool isEmptyStmt() const;
        bool isEmptyCompStmt() const;
};
