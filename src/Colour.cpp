#include "Colour.h"

#include <unistd.h>

#include "Token.h"

namespace colour {
    static const char* code(const char* ansi) {
        static const bool enabled = isatty(STDOUT_FILENO);
        return enabled ? ansi : "";
    }

    const char* red()    { return code("\033[31m"); }
    const char* green()  { return code("\033[32m"); }
    const char* yellow() { return code("\033[33m"); }
    const char* cyan()   { return code("\033[36m"); }
    const char* bold()   { return code("\033[1m"); }
    const char* reset()  { return code("\033[0m"); }

    const char* forToken(int kind) {
        // keywords
        if (kind >= Token::BOOLEAN && kind <= Token::WHILE) {
            return code("\033[1;35m");  
        }
        // operators
        if (kind >= Token::PLUS && kind <= Token::OROR) {
            return code("\033[33m");
        }
        // separators
        if (kind >= Token::LCURLY && kind <= Token::COMMA) {
            return code("\033[90m");
        }

        switch (kind) {
            case Token::ID:             return code("\033[36m");    // cyan
            case Token::INTLITERAL:     return code("\033[94m");    // bright blue
            case Token::FLOATLITERAL:   return code("\033[34m");    // blue
            case Token::BOOLEANLITERAL: return code("\033[95m");    // bright magenta
            case Token::STRINGLITERAL:  return code("\033[32m");    // green
            case Token::ERROR:          return code("\033[1;31m");  // red
            case Token::END_OF_FILE:    return code("\033[2m");     // grey
            default:                    return "";
        }
    }
}
