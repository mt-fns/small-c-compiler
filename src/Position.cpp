#include "Position.h"

Position::Position() : Position(0, 0, 0, 0) {}

Position::Position(int lineStart, int lineFinish) : Position(lineStart, lineFinish, 0, 0) {}

Position::Position(int lineStart, int lineFinish, int charStart, int charFinish) :
    lineStart{lineStart},
    lineFinish{lineFinish},
    charStart{charStart},
    charFinish{charFinish} {}

std::ostream& operator<<(std::ostream& os, const Position& p) {
    return os << p.lineStart << "(" << p.charStart << ").." << p.lineFinish << "(" << p.charFinish << ")";
}
