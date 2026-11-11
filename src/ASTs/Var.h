#pragma once

#include "Position.h"
#include "ASTs/AST.h"

class Type;

// This is an abstract class. Currently, Var has just one subclass, SimpleVar, but we may add more in future.
class Var : public AST {
    public:
        // set by the type checker; not owned by this node
        Type* type = nullptr;

        Var(Position position);
};
