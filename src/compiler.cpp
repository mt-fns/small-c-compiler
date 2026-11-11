#include <cstdlib>
#include <iostream>
#include <string>

#include "Colour.h"
#include "ErrorReporter.h"
#include "Recogniser.h"
#include "Scanner.h"
#include "Source.h"
#include "SyntaxError.h"
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

    // Scanner
    std::cout << colour::note() << "[Running Scanner]" << colour::reset() << '\n';
    Source scannerSource(inputFilename);
    ErrorReporter scannerReporter;
    Scanner scanner(scannerSource, scannerReporter);

    scanner.enableDebugging();
    while (scanner.getToken().kind != Token::END_OF_FILE) {}

    // Recogniser
    std::cout << '\n' << colour::note() << "[Running Recogniser]" << colour::reset() << '\n';
    Source source(inputFilename);
    ErrorReporter reporter;
    Scanner recogniserScanner(source, reporter);
    Recogniser recogniser(recogniserScanner, reporter);

    try {
        recogniser.parseTopLevel();
    } catch (const SyntaxError&) {
        // already reported by the recogniser
    }

    if (reporter.getNumErrors() == 0) {
        std::cout << "Compilation was successful.\n";
        return 0;
    }

    std::cout << "Compilation was unsuccessful.\n";
    return 1;
}
