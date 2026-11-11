// expect: fail
// for-stmt always has two ';' separators, even when clauses are empty.
// Error expected at the ')' on line 7.

void main() {
    int i;
    for (i = 0; i < 10) i = i + 1;
}
