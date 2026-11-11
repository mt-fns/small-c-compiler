#include "ASTs/Type.h"

#include "ASTs/ArrayType.h"
#include "ASTs/BooleanType.h"
#include "ASTs/ErrorType.h"
#include "ASTs/FloatType.h"
#include "ASTs/IntType.h"
#include "ASTs/StringType.h"
#include "ASTs/VoidType.h"

Type::Type(Position position) : AST{position} {}

bool Type::isVoidType() const {
    return dynamic_cast<const VoidType*>(this) != nullptr;
}

bool Type::isIntType() const {
    return dynamic_cast<const IntType*>(this) != nullptr;
}

bool Type::isFloatType() const {
    return dynamic_cast<const FloatType*>(this) != nullptr;
}

bool Type::isStringType() const {
    return dynamic_cast<const StringType*>(this) != nullptr;
}

bool Type::isBooleanType() const {
    return dynamic_cast<const BooleanType*>(this) != nullptr;
}

bool Type::isArrayType() const {
    return dynamic_cast<const ArrayType*>(this) != nullptr;
}

bool Type::isPrimitiveType() const {
    return isVoidType() || isIntType() || isFloatType() || isBooleanType();
}

bool Type::isErrorType() const {
    return dynamic_cast<const ErrorType*>(this) != nullptr;
}

Type* Type::getElementType() const {
    return nullptr;
}
