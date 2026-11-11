#pragma once

#include <any>
#include <string>

#include "Position.h"
#include "ASTs/Terminal.h"

class FloatLiteral : public Terminal {
    public:
        FloatLiteral(std::string value, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
