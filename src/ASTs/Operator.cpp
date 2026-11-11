#include "ASTs/Operator.h"

#include <utility>

#include "ASTs/Visitor.h"

Operator::Operator(std::string value, Position position) : Terminal{std::move(value), position} {}

std::any Operator::visit(Visitor& v, std::any o) {
    return v.visitOperator(this, o);
}
