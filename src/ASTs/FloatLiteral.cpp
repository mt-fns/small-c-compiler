#include "ASTs/FloatLiteral.h"

#include <utility>

#include "ASTs/Visitor.h"

FloatLiteral::FloatLiteral(std::string value, Position position) : Terminal{std::move(value), position} {}

std::any FloatLiteral::visit(Visitor& v, std::any o) {
    return v.visitFloatLiteral(this, o);
}
