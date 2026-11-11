// expect: fail
// compound-stmt only allows declarations before the first statement.
// Error expected at the 'int' on line 8.

void main() {
    int x;
    x = 1;
    int y;
}
