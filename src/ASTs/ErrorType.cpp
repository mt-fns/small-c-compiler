#include "ASTs/ErrorType.h"

#include "ASTs/Visitor.h"

ErrorType::ErrorType(Position position) : Type{position} {}

bool ErrorType::equals(const Type*) const {
    return true;
}

bool ErrorType::assignable(const Type*) const {
    return true;
}

std::unique_ptr<Type> ErrorType::cloneType() const {
    return std::make_unique<ErrorType>(position);
}

std::string ErrorType::toString() const {
    return "error";
}

std::any ErrorType::visit(Visitor& v, std::any o) {
    return v.visitErrorType(this, o);
}
