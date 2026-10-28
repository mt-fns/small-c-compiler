#include <cstdlib>
#include <iostream>
#include <string>

#include "Colour.h"
#include "ErrorReporter.h"
#include "Recogniser.h"
#include "Scanner.h"
#include "Source.h"
#include "Token.h"

static void cmdLineOptions() {
    std::cout << "\n[Usage: compiler filename]\n";
    std::exit(1);
}

int main(int argc, char* argv[]) {
    std::cout << colour::bold() << "Small C Compiler" << colour::reset() << "\n\n";

    if (argc < 2) {
        std::cout << colour::error() << "[Error]: " << colour::reset() << "no input file\n";
        cmdLineOptions();
    }
    std::string inputFilename = argv[1];

    Source source(inputFilename);
    ErrorReporter reporter;

    // Scanner
    std::cout << colour::note() << "[Running Scanner]" << colour::reset() << '\n';
    Scanner scanner(source, reporter);

    scanner.enableDebugging();
    while (scanner.getToken().kind != Token::END_OF_FILE) {}

    // Recogniser
    Scanner scanner2(source, reporter);
    Recogniser recogniser(scanner, reporter);

    recogniser.parseProgram();
    // TODO: call parseProgram and read from error reporter to check if program copmiled
    // also implement syntax error in parseProgram, comments and strings in scanner, and parseProgram functions



    return 0;
}
