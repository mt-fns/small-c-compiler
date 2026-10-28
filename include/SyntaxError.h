#pragma once

#include <stdexcept>
#include <string>

// The parser uses panic-mode recovery: on the first syntax error it reports
// the error with its position, then throws this to stop parsing.
class SyntaxError : public std::runtime_error {
    public:
        SyntaxError();

        explicit SyntaxError(const std::string& message);
};
