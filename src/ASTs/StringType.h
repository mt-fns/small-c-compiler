#pragma once

#include <any>
#include <memory>
#include <string>

#include "Position.h"
#include "ASTs/Type.h"

// Used for performing type checking.
// No variables can be declared to have a string type, but
// a string will be deduced to have a string type by the type checker.
class StringType : public Type {
    public:
        StringType(Position position);

        bool equals(const Type* obj) const override;

        bool assignable(const Type* obj) const override;

        std::unique_ptr<Type> cloneType() const override;

        std::string toString() const override;

        std::any visit(Visitor& v, std::any o) override;
};
