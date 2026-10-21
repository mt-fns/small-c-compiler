#pragma once

#include <cstddef>
#include <string>

class Source {
    public:
        static constexpr char eof = '\0';

        Source(const std::string& filename);

        char getNextChar();

        char inspectChar(int nthChar) const;

    private:
        std::string contents;
        std::size_t pos = 0;
};
