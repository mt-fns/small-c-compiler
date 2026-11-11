#include "ASTs/IntLiteral.h"

#include <utility>

#include "ASTs/Visitor.h"

IntLiteral::IntLiteral(std::string value, Position position) : Terminal{std::move(value), position} {}

std::any IntLiteral::visit(Visitor& v, std::any o) {
    return v.visitIntLiteral(this, o);
}
