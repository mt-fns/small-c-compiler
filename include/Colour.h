#pragma once

// Terminal colours by role. Uses 24-bit colour when the terminal supports it
// (COLORTERM=truecolor), otherwise the 256-colour fallback. Each returns ""
// when stdout isn't a terminal (redirected or piped), so that output stays plain.
namespace colour {
    // semantic roles
    const char* keyword();  // while, return
    const char* type();     // int, float, boolean, void
    const char* value();    // identifiers
    const char* number();   // numeric literals
    const char* string();   // string literals
    const char* special();
    const char* text();
    const char* muted();    // punctuation, operators
    const char* comment();

    // diagnostics
    const char* error();
    const char* warning();
    const char* note();
    const char* fix();

    const char* bold();
    const char* reset();

    // the colour used to print a token of the given kind
    const char* forToken(int kind);
}
