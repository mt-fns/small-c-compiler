#pragma once

#include <any>
#include <string>

#include "Position.h"
#include "ASTs/Terminal.h"

class Operator : public Terminal {
    public:
        Operator(std::string value, Position position);

        std::any visit(Visitor& v, std::any o) override;
};
