#pragma once

#include <string>

#include "Position.h"

class ErrorReporter {
    public:
        ErrorReporter();
        
        void reportError(const std::string& message, const std::string& tokenName, const Position& pos);

        void reportRestriction(const std::string& message);

        int getNumErrors() const;

    private:
        int numErrors;
};
