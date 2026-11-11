// expect: pass
// fun-signature with no parameters, one parameter, several parameters and
// array parameters (with and without a size), mixed with declarations.

void noParams() {}

int one(int x) { return x; }

float many(int a, float b, void c) { return b; }

int arrays(int a[], float b[8]) { return a[0]; }

int global;

void last() {}
