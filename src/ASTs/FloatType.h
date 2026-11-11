#pragma once

#include <any>
#include <memory>
#include <string>

#include "Position.h"
#include "ASTs/Type.h"

class FloatType : public Type {
    public:
        FloatType(Position position);

        bool equals(const Type* obj) const override;

        bool assignable(const Type* obj) const override;

        std::unique_ptr<Type> cloneType() const override;

        std::string toString() const override;

        std::any visit(Visitor& v, std::any o) override;
};
