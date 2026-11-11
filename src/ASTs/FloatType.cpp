#include "ASTs/FloatType.h"

#include "ASTs/Visitor.h"

FloatType::FloatType(Position position) : Type{position} {}

bool FloatType::equals(const Type* obj) const {
    if (obj != nullptr && obj->isErrorType()) {
        return true;
    }
    return obj != nullptr && obj->isFloatType();
}

bool FloatType::assignable(const Type* obj) const {
    if (obj != nullptr && obj->isErrorType()) {
        return true;
    }
    return obj != nullptr && (obj->isIntType() || obj->isFloatType());
}

std::unique_ptr<Type> FloatType::cloneType() const {
    return std::make_unique<FloatType>(position);
}

std::string FloatType::toString() const {
    return "float";
}

std::any FloatType::visit(Visitor& v, std::any o) {
    return v.visitFloatType(this, o);
}
