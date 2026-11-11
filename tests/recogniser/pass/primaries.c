// expect: pass
// prim-ident as a plain variable, a call with no arguments, a call with
// arguments, nested calls and array indexing; prim-literal for every literal
// kind, including string escapes.

int a[10];

void main() {
    int i;

    i = getInt();
    putInt(i);
    putIntLn(gcd(i, getInt()));
    a[0] = 1;
    a[i + 1] = a[a[0]];
    a[f(i)] = f(a[i], g(), "str");
    putString("hello, world\n");
    putString("");
    putString("tab\t quote\" backslash\\ ");
    putFloat(3.14);
    putFloat(.5);
}
