#include "Colour.h"

#include <cstdlib>
#include <string_view>
#include <unistd.h>

#include "Token.h"

namespace colour {
    enum class Mode { None, Xterm256, TrueColour };

    static Mode mode() {
        static const Mode m = [] {
            if (!isatty(STDOUT_FILENO)) {
                return Mode::None;
            }
            const char* colorterm = std::getenv("COLORTERM");
            if (colorterm != nullptr) {
                std::string_view ct = colorterm;
                if (ct == "truecolor" || ct == "24bit") {
                    return Mode::TrueColour;
                }
            }
            return Mode::Xterm256;
        }();
        return m;
    }

    // rgb is the 24-bit escape, xterm the 256-colour fallback
    static const char* pick(const char* rgb, const char* xterm) {
        switch (mode()) {
            case Mode::TrueColour: return rgb;
            case Mode::Xterm256:   return xterm;
            default:               return "";
        }
    }

    // semantic roles
    const char* keyword() { return pick("\033[38;2;199;146;234m", "\033[38;5;176m"); }  // #c792ea purple
    const char* type()    { return pick("\033[38;2;127;209;199m", "\033[38;5;116m"); }  // #7fd1c7 teal
    const char* value()   { return pick("\033[38;2;130;170;255m", "\033[38;5;111m"); }  // #82aaff blue
    const char* number()  { return pick("\033[38;2;242;179;111m", "\033[38;5;215m"); }  // #f2b36f orange
    const char* string()  { return pick("\033[38;2;163;209;122m", "\033[38;5;150m"); }  // #a3d17a green
    const char* special() { return pick("\033[38;2;232;140;165m", "\033[38;5;175m"); }  // #e88ca5 pink
    const char* text()    { return pick("\033[38;2;213;217;224m", "\033[38;5;253m"); }  // #d5d9e0
    const char* muted()   { return pick("\033[38;2;138;146;160m", "\033[38;5;246m"); }  // #8a92a0
    const char* comment() { return pick("\033[38;2;107;115;128m", "\033[38;5;243m"); }  // #6b7380

    // diagnostics
    const char* error()   { return pick("\033[38;2;240;113;120m", "\033[38;5;210m"); }  // #f07178
    const char* warning() { return pick("\033[38;2;255;203;107m", "\033[38;5;221m"); }  // #ffcb6b
    const char* note()    { return pick("\033[38;2;130;170;255m", "\033[38;5;111m"); }  // #82aaff
    const char* fix()     { return pick("\033[38;2;163;209;122m", "\033[38;5;150m"); }  // #a3d17a

    const char* bold()    { return pick("\033[1m", "\033[1m"); }
    const char* reset()   { return pick("\033[0m", "\033[0m"); }

    const char* forToken(int kind) {
        switch (kind) {
            // type keywords
            case Token::BOOLEAN:
            case Token::FLOAT:
            case Token::INT:
            case Token::VOID:
                return type();
        }

        // other keywords
        if (kind >= Token::BOOLEAN && kind <= Token::WHILE) {
            return keyword();
        }
        // operators and separators
        if (kind >= Token::PLUS && kind <= Token::COMMA) {
            return muted();
        }

        switch (kind) {
            case Token::ID:             return value();
            case Token::INTLITERAL:     return number();
            case Token::FLOATLITERAL:   return number();
            case Token::BOOLEANLITERAL: return number();
            case Token::STRINGLITERAL:  return string();
            case Token::ERROR:          return error();
            case Token::END_OF_FILE:    return comment();
            default:                    return text();
        }
    }
}
