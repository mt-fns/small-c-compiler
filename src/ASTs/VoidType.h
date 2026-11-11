#pragma once

#include <any>
#include <memory>
#include <string>

#include "Position.h"
#include "ASTs/Type.h"

// According to the VC grammar, "void x" will be considered
// to be syntactically legal by our parser
// but will be ruled out as being semantically illegal by our
// type checker.
class VoidType : public Type {
    public:
        VoidType(Position position);

        bool equals(const Type* obj) const override;

        bool assignable(const Type* obj) const override;

        std::unique_ptr<Type> cloneType() const override;

        std::string toString() const override;

        std::any visit(Visitor& v, std::any o) override;
};
