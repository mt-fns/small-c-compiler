#pragma once

#include <memory>

#include "Position.h"
#include "ASTs/AST.h"

class Type : public AST {
    public:
        Type(Position position);

        // if obj and "this" are of the same type
        virtual bool equals(const Type* obj) const = 0;

        // In v = e, let "this" be the type of v and obj be the type of e.
        // returns true if obj is assignment compatible with "this" and
        // false otherwise.
        virtual bool assignable(const Type* obj) const = 0;

        bool isVoidType() const;
        bool isIntType() const;
        bool isFloatType() const;
        bool isStringType() const;
        bool isBooleanType() const;
        bool isArrayType() const;
        bool isPrimitiveType() const;
        bool isErrorType() const;

        // Can be used for creating the AST for multiple-variable declarations
        virtual std::unique_ptr<Type> cloneType() const = 0;

        // the element type of an array type, nullptr for every other type
        virtual Type* getElementType() const;
};
