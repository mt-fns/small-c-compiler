#pragma once

#include <any>
#include <string>

#include "Position.h"
#include "ASTs/Terminal.h"

// Used for representing a single Boolean literal: true or false.
class BooleanLiteral : public Terminal {
    public:
        BooleanLiteral(std::string value, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
