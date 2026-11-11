#pragma once

#include <any>
#include <string>

#include "Position.h"
#include "ASTs/Terminal.h"

class IntLiteral : public Terminal {
    public:
        IntLiteral(std::string value, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
