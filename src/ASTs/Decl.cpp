#include "ASTs/Decl.h"

#include "ASTs/FuncDecl.h"
#include "ASTs/GlobalVarDecl.h"
#include "ASTs/LocalVarDecl.h"
#include "ASTs/ParaDecl.h"

Decl::Decl(Position position) : AST{position} {}

bool Decl::isFuncDecl() const {
    return dynamic_cast<const FuncDecl*>(this) != nullptr;
}

bool Decl::isGlobalVarDecl() const {
    return dynamic_cast<const GlobalVarDecl*>(this) != nullptr;
}

bool Decl::isLocalVarDecl() const {
    return dynamic_cast<const LocalVarDecl*>(this) != nullptr;
}

bool Decl::isParaDecl() const {
    return dynamic_cast<const ParaDecl*>(this) != nullptr;
}

std::string Decl::toString() const {
    return "Decl"; // should be overridden
}
