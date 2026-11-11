#include "ASTs/ArrayType.h"

#include <utility>

#include "ASTs/EmptyExpr.h"
#include "ASTs/Visitor.h"

ArrayType::ArrayType(std::unique_ptr<Type> tAST, std::unique_ptr<Expr> dAST, Position position) :
    Type{position},
    T{std::move(tAST)},
    E{std::move(dAST)} {
    T->parent = this;
    E->parent = this;
}

bool ArrayType::equals(const Type*) const {
    return false; // An array name cannot appear alone in VC.
                  // For example, a = b is not allowed if a and b are
                  // array names. Thus, this method should never be called
}

bool ArrayType::assignable(const Type*) const {
    return false; // a = b is not a legal assignment in VC when a and b are arrays
                  // But an array can be passed as an argument in a function call. So
                  // you need to handle this as a special case without relying on this method!
}

std::unique_ptr<Type> ArrayType::cloneType() const {
    return std::make_unique<ArrayType>(T->cloneType(), std::make_unique<EmptyExpr>(position), position);
}

Type* ArrayType::getElementType() const {
    return T.get();
}

std::string ArrayType::toString() const {
    if (T->isIntType()) {
        return "[I";
    } else if (T->isFloatType()) {
        return "[F";
    } else if (T->isBooleanType()) {
        return "[Z";
    } else if (T->isVoidType()) {
        return "[V"; // will be detected as semantic errors
    } else {
        return "[*"; // should not happen
    }
}

std::any ArrayType::visit(Visitor& v, std::any o) {
    return v.visitArrayType(this, o);
}
