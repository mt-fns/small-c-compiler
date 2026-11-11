#pragma once

#include <any>
#include <memory>
#include <string>

#include "Position.h"
#include "ASTs/Expr.h"
#include "ASTs/Type.h"

// Used for representing the type of an array.
class ArrayType : public Type {
    public:
        std::unique_ptr<Type> T;
        std::unique_ptr<Expr> E;

        ArrayType(std::unique_ptr<Type> tAST, std::unique_ptr<Expr> dAST, Position position);

        bool equals(const Type* obj) const override;

        bool assignable(const Type* obj) const override;

        std::unique_ptr<Type> cloneType() const override;

        std::string toString() const override;

        Type* getElementType() const override;

        std::any visit(Visitor& v, std::any o) override;
};
