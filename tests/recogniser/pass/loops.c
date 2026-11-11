// expect: pass
// for-stmt with every combination of its optional expressions, while-stmt,
// break and continue, and nested loops.

void loops(int n) {
    int i;
    int j;

    for (;;) break;
    for (i = 0;;) break;
    for (; i < n;) i = i + 1;
    for (;; i = i + 1) if (i > n) break;
    for (i = 0; i < n; i = i + 1) {
        for (j = 0; j < i; j = j + 1) {
            if (j == 2) continue;
            if (j == 3) break;
        }
    }

    while (i) i = i - 1;
    while (1) {
        while (n > 0) { n = n - 1; continue; }
        break;
    }
}
