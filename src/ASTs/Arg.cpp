#include "ASTs/Arg.h"

#include <utility>

#include "ASTs/Visitor.h"

Arg::Arg(std::unique_ptr<Expr> eAST, Position position) :
    Expr{position},
    E{std::move(eAST)} {
    E->parent = this;
}

std::string Arg::toString() const {
    return "Arg(" + E->toString() + ")";
}

std::any Arg::visit(Visitor& v, std::any o) {
    return v.visitArg(this, o);
}
