#pragma once

namespace colour {
    const char* red();
    const char* green();
    const char* yellow();
    const char* cyan();
    const char* bold();
    const char* reset();

    // the colour used to print a token of the given kind
    const char* forToken(int kind);
}
