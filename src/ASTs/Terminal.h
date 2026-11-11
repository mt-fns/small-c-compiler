#pragma once

#include <string>

#include "Position.h"
#include "ASTs/AST.h"

class Terminal : public AST {
    public:
        std::string spelling;

        Terminal(std::string value, Position position);

        std::string toString() const override;
};
