#pragma once

#include <any>
#include <ostream>
#include <string>

#include "Position.h"

class Visitor;

// The top-level abstract class for representing an AST node.
//
// A node owns its children through std::unique_ptr. parent and every other
// raw pointer in the tree is a non-owning back reference.
class AST {
    public:
        Position position;
        AST* parent = nullptr;

        AST(Position position);

        virtual ~AST() = default;

        // nodes are linked to their parent by address, so they can't be copied
        AST(const AST&) = delete;
        AST& operator=(const AST&) = delete;

        Position getPosition() const;

        virtual std::any visit(Visitor& v, std::any o) = 0;

        virtual std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const AST& ast);
