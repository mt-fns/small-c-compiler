// expect: fail
// expr-list ::= expression { ',' expression } does not allow a trailing comma.
// Error expected at the ')' on line 6.

void main() {
    f(1, 2,);
}
