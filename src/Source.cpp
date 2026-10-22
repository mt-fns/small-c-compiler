#include "Source.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>

#include "Colour.h"

Source::Source(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        std::cout << colour::error() << "[# vc #]: can't read: " << colour::reset() << filename << '\n';
        std::exit(1);
    }

    contents.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
}

char Source::getNextChar() {
    if (pos >= contents.size()) {
        return eof;
    }
    return contents[pos++];
}

char Source::inspectChar(int nthChar) const {
    std::size_t i = pos + nthChar - 1;
    if (i >= contents.size()) {
        return eof;
    }
    return contents[i];
}
