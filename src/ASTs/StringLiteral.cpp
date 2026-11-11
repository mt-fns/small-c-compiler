#include "ASTs/StringLiteral.h"

#include <utility>

#include "ASTs/Visitor.h"

StringLiteral::StringLiteral(std::string value, Position position) : Terminal{std::move(value), position} {}

std::any StringLiteral::visit(Visitor& v, std::any o) {
    return v.visitStringLiteral(this, o);
}
