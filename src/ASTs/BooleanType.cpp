#include "ASTs/BooleanType.h"

#include "ASTs/Visitor.h"

BooleanType::BooleanType(Position position) : Type{position} {}

bool BooleanType::equals(const Type* obj) const {
    if (obj != nullptr && obj->isErrorType()) {
        return true;
    }
    return obj != nullptr && obj->isBooleanType();
}

bool BooleanType::assignable(const Type* obj) const {
    return equals(obj);
}

std::unique_ptr<Type> BooleanType::cloneType() const {
    return std::make_unique<BooleanType>(position);
}

std::string BooleanType::toString() const {
    return "boolean";
}

std::any BooleanType::visit(Visitor& v, std::any o) {
    return v.visitBooleanType(this, o);
}
