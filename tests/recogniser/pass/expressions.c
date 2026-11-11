// expect: pass
// Every binary operator at every precedence level, right-associative
// chained assignment, nested unary operators and parentheses.

int main() {
    int a;
    int b;
    int c;
    float f;

    a = b = c = 1;
    a = b || c && a;
    a = (b || c) && a;
    a = b == c != a;
    a = b < c <= a > b >= c;
    a = b + c - a * b / c;
    a = (b + c) * (a - b) / (c);
    a = -b;
    a = - - b;
    a = !!b;
    a = +-!+c;
    a = -(b + c) * !a;
    f = 1.5 * .5 - 2.0 / 4.0;
    a = 1 + 2 == 3 && 4 < 5 || !0;
    a;
    1;
    (a);
    return a;
}
