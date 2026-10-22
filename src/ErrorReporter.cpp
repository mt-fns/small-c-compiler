#include "ErrorReporter.h"

#include <iostream>

#include "Colour.h"

ErrorReporter::ErrorReporter() : numErrors{0} {}

void ErrorReporter::reportError(const std::string& message, const std::string& tokenName, const Position& pos) {
    std::cout << colour::red() << "ERROR: " << colour::reset() << pos << ": ";

    if (message.find('%') == std::string::npos) {
        std::cout << message;
        if (!tokenName.empty()) {
            std::cout << ": " << tokenName;
        }
    } else {
        for (char ch : message) {
            if (ch == '%') {
                std::cout << tokenName;
            } else {
                std::cout << ch;
            }
        }
    }

    std::cout << '\n';
    numErrors++;
}

void ErrorReporter::reportRestriction(const std::string& message) {
    std::cout << colour::yellow() << "RESTRICTION: " << colour::reset() << message << '\n';
}

int ErrorReporter::getNumErrors() const {
    return numErrors;
}
