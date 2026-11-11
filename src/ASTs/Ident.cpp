#include "ASTs/Ident.h"

#include <utility>

#include "ASTs/Visitor.h"

Ident::Ident(std::string value, Position position) : Terminal{std::move(value), position} {}

std::any Ident::visit(Visitor& v, std::any o) {
    return v.visitIdent(this, o);
}
