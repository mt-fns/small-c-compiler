#include "ASTs/AST.h"

AST::AST(Position position) : position{position} {}

Position AST::getPosition() const {
    return position;
}

std::string AST::toString() const {
    return "AST";
}

std::ostream& operator<<(std::ostream& os, const AST& ast) {
    return os << ast.toString();
}
