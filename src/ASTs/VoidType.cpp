#include "ASTs/VoidType.h"

#include "ASTs/Visitor.h"

VoidType::VoidType(Position position) : Type{position} {}

bool VoidType::equals(const Type* obj) const {
    if (obj != nullptr && obj->isErrorType()) {
        return true;
    }
    return obj != nullptr && obj->isVoidType();
}

bool VoidType::assignable(const Type* obj) const {
    return equals(obj);
}

std::unique_ptr<Type> VoidType::cloneType() const {
    return std::make_unique<VoidType>(position);
}

std::string VoidType::toString() const {
    return "void";
}

std::any VoidType::visit(Visitor& v, std::any o) {
    return v.visitVoidType(this, o);
}
