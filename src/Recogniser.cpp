#include "Recogniser.h"

Recogniser::Recogniser(Scanner& scanner, ErrorReporter& reporter) :
    scanner{scanner},
    reporter{reporter},
    currentToken{scanner.getToken()} {}

void Recogniser::match(int tokenExpected) {
    if (currentToken.kind == tokenExpected) {
        currentToken = scanner.getToken();
    } else {
        // TODO: throw a syntax error here once we have the syntax error class
        std::cerr << "EROR IN MATCH" << std::endl;
    }
}

void Recogniser::accept() {
    currentToken = scanner.getToken();
}

