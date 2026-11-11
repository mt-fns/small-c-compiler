#include "ASTs/IntType.h"

#include "ASTs/Visitor.h"

IntType::IntType(Position position) : Type{position} {}

bool IntType::equals(const Type* obj) const {
    if (obj != nullptr && obj->isErrorType()) {
        return true;
    }
    return obj != nullptr && obj->isIntType();
}

bool IntType::assignable(const Type* obj) const {
    return equals(obj);
}

std::unique_ptr<Type> IntType::cloneType() const {
    return std::make_unique<IntType>(position);
}

std::string IntType::toString() const {
    return "int";
}

std::any IntType::visit(Visitor& v, std::any o) {
    return v.visitIntType(this, o);
}
