#include <cstdlib>
#include <iostream>
#include <string>

#include "Colour.h"
#include "ErrorReporter.h"
#include "Scanner.h"
#include "Source.h"
#include "Token.h"

static void cmdLineOptions() {
    std::cout << "\n[Usage: compiler filename]\n";
    std::exit(1);
}

int main(int argc, char* argv[]) {
    std::cout << colour::bold() << "Minimal C compiler" << colour::reset() << "\n\n";

    if (argc < 2) {
        std::cout << colour::red() << "[Error]: " << colour::reset() << "no input file\n";
        cmdLineOptions();
    }
    std::string inputFilename = argv[1];

    Source source(inputFilename);
    ErrorReporter reporter;

    std::cout << colour::green() << "[Running Scanner]" << colour::reset() << '\n';
    Scanner scanner(source, reporter);

    scanner.enableDebugging();
    while (scanner.getToken().kind != Token::END_OF_FILE) {}

    return 0;
}
