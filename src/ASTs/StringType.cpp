#include "ASTs/StringType.h"

#include "ASTs/Visitor.h"

StringType::StringType(Position position) : Type{position} {}

bool StringType::equals(const Type* obj) const {
    if (obj != nullptr && obj->isErrorType()) {
        return true;
    }
    return obj != nullptr && obj->isStringType();
}

bool StringType::assignable(const Type* obj) const {
    if (obj != nullptr && obj->isErrorType()) {
        return true;
    }
    return obj != nullptr && obj->isStringType();
}

std::unique_ptr<Type> StringType::cloneType() const {
    return std::make_unique<StringType>(position);
}

std::string StringType::toString() const {
    return "string";
}

std::any StringType::visit(Visitor& v, std::any o) {
    return v.visitStringType(this, o);
}
