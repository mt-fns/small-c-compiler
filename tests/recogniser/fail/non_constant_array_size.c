// expect: fail
// declarator ::= identifier [ '[' [ int-const ] ']' ]
// The array size must be an int-const, not an identifier or expression.
// Error expected at the 'n' on line 7.

void main() {
    int a[n];
}
