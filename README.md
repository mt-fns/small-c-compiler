# Small C Compiler

**scc** is a compiler that compiles a subset of C. The C subset that **scc** recognises is defined by this EBNF grammar:


```ebnf
Grammar::Syntactic::SmallC

+Syntax::TopLevel

top-level       ::= { top-level-elem }

top-level-elem  ::= fun-definition | decl-stmt

+Syntax::Functions

fun-definition  ::= fun-signature compound-stmt

fun-signature   ::= tyy-decl identifier '(' [ tyyid-pair-list ] ')'

+Syntax::Declarations

decl-stmt       ::= tyy-decl init-list ';'

init-list       ::= init-decl { ',' init-decl }

init-decl       ::= declarator [ '=' initialiser ]

declarator      ::= identifier [ '[' [ int-const ] ']' ]

initialiser     ::= expression
                  | '{' expr-list '}'

+Syntax::Statements

compound-stmt   ::= '{' { decl-stmt } { statement } '}'

statement       ::= compound-stmt
                  | if-stmt
                  | for-stmt
                  | while-stmt
                  | break-stmt
                  | continue-stmt
                  | return-stmt
                  | expr-stmt

if-stmt         ::= kw-if '(' expression ')' statement [ kw-else statement ]

for-stmt        ::= kw-for '(' [ expression ] ';' [ expression ] ';' [ expression ] ')' statement

while-stmt      ::= kw-while '(' expression ')' statement

break-stmt      ::= kw-break ';'

continue-stmt   ::= kw-continue ';'

return-stmt     ::= kw-return [ expression ] ';'

expr-stmt       ::= [ expression ] ';'

+Syntax::Expression

expr-list       ::= expression { ',' expression }

expression      ::= assign-expr

assign-expr     ::= logor-expr [ '=' assign-expr ]

+Syntax::Binary-Expression

logor-expr      ::= logand-expr { "||" logand-expr }

logand-expr     ::= eqop-expr { "&&" eqop-expr }

eqop-expr       ::= relop-expr { ( "==" | "!=" ) relop-expr }

relop-expr      ::= add-expr { ( '<' | "<=" | '>' | ">=" ) add-expr }

add-expr        ::= mult-expr { ( '+' | '-' ) mult-expr }

mult-expr       ::= unary { ( '*' | '/' ) unary }

+Syntax::Unary-Expression

unary           ::= '+' unary
                  | '-' unary
                  | '!' unary
                  | primary

+Syntax::Primary

primary         ::= prim-expr
                  | prim-ident
                  | prim-literal

prim-expr       ::= '(' expression ')'

prim-ident      ::= identifier [ '(' [ expr-list ] ')' | '[' expression ']' ]

prim-literal    ::= int-const | float-const | str-const

+Syntax::Types

tyyid-pair-list ::= tyyid-pair { ',' tyyid-pair }

tyyid-pair      ::= tyy-decl declarator

tyy-decl        ::= kw-void
                  | kw-int
                  | kw-float

Grammar::Lexical::SmallC

+Lexical::Keywords

kw-break        ::= "break"
kw-continue     ::= "continue"
kw-else         ::= "else"
kw-float        ::= "float"
kw-for          ::= "for"
kw-if           ::= "if"
kw-int          ::= "int"
kw-return       ::= "return"
kw-void         ::= "void"
kw-while        ::= "while"

+Lexical::LiteralTokens

int-const       ::= digit { digit }

float-const     ::= [ int-const ] '.' int-const

str-const       ::= '"' { character } '"'

identifier      ::= ( letter | '_' ) { letter | digit | '_' }

letter          ::= 'a' | 'b' | ... | 'z' | 'A' | 'B' | ... | 'Z'

digit           ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

character       ::= printable | char-escape

printable       ::= ' ' | '!' | '#' | ... | '|' | '}' | '~'

char-escape     ::= '\' escapable

escapable       ::= 'n' | 'a' | 'b' | 't' | 'f' | 'r' | 'v' | '\' | "'" | '"' | '?' | '0'

comment         ::= "//" { any-char } "\n"
                  | "/*" { any-char } "*/"
```
