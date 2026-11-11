#include "ASTs/Terminal.h"

#include <utility>

Terminal::Terminal(std::string value, Position position) :
    AST{position},
    spelling{std::move(value)} {}

std::string Terminal::toString() const {
    return spelling;
}
