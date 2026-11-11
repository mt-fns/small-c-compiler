// expect: pass
// if-stmt with and without else, else-if chains, a dangling else and
// bodies that are single statements or blocks.

int sign(int x) {
    if (x < 0) return -1;

    if (x == 0) {
        return 0;
    } else if (x > 100) {
        return 2;
    } else {
        ;
    }

    if (x) if (x > 1) x = 1; else x = 2;

    if (x != 1)
        if (x >= 2)
            return 3;
        else
            return 4;
    else
        return 1;
}
