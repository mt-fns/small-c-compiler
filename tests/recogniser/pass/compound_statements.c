// expect: pass
// compound-stmt ::= '{' { decl-stmt } { statement } '}'
// Declarations before statements, nested blocks with their own declarations,
// empty blocks and empty expression statements.

void main() {
    int x;
    float y = 2.0;
    int z[4];

    {}
    ;
    ;;
    {
        int inner = x;
        {
            float deeper;
            deeper = inner;
        }
    }
    x = 1;
}
