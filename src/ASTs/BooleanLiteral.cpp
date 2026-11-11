#include "ASTs/BooleanLiteral.h"

#include <utility>

#include "ASTs/Visitor.h"

BooleanLiteral::BooleanLiteral(std::string value, Position position) : Terminal{std::move(value), position} {}

std::any BooleanLiteral::visit(Visitor& v, std::any o) {
    return v.visitBooleanLiteral(this, o);
}
