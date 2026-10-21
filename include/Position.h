#pragma once

#include <ostream>

class Position {
    public:
        int lineStart, lineFinish;
        int charStart, charFinish;

        Position();

        Position(int lineStart, int lineFinish);

        Position(int lineStart, int lineFinish, int charStart, int charFinish);
};

std::ostream& operator<<(std::ostream& os, const Position& p);
