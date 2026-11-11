#include "ASTs/Program.h"

#include <utility>

#include "ASTs/Visitor.h"

Program::Program(std::unique_ptr<ASTList<Decl>> dlAST, Position position) :
    AST{position},
    FL{std::move(dlAST)} {
    FL->parent = this;
}

std::any Program::visit(Visitor& v, std::any o) {
    return v.visitProgram(this, o);
}
