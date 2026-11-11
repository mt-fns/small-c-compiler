cmake_minimum_required(VERSION 3.20)
project(myproj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)          # -std=c++20, not gnu++20
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # for clangd

add_executable(compiler
    src/Colour.cpp
    src/compiler.cpp
    src/ErrorReporter.cpp
    src/Position.cpp
    src/Parser.cpp
    src/Recogniser.cpp
    src/Scanner.cpp
    src/Source.cpp
    src/SyntaxError.cpp
    src/Token.cpp
    src/ASTs/Arg.cpp
    src/ASTs/ArgList.cpp
    src/ASTs/ArrayExpr.cpp
    src/ASTs/ArrayExprList.cpp
    src/ASTs/ArrayInitExpr.cpp
    src/ASTs/ArrayType.cpp
    src/ASTs/AssignExpr.cpp
    src/ASTs/AST.cpp
    src/ASTs/BinaryExpr.cpp
    src/ASTs/BooleanExpr.cpp
    src/ASTs/BooleanLiteral.cpp
    src/ASTs/BooleanType.cpp
    src/ASTs/BreakStmt.cpp
    src/ASTs/CallExpr.cpp
    src/ASTs/CompoundStmt.cpp
    src/ASTs/ContinueStmt.cpp
    src/ASTs/Decl.cpp
    src/ASTs/DeclList.cpp
    src/ASTs/EmptyArgList.cpp
    src/ASTs/EmptyArrayExprList.cpp
    src/ASTs/EmptyCompStmt.cpp
    src/ASTs/EmptyDeclList.cpp
    src/ASTs/EmptyExpr.cpp
    src/ASTs/EmptyParaList.cpp
    src/ASTs/EmptyStmt.cpp
    src/ASTs/EmptyStmtList.cpp
    src/ASTs/ErrorType.cpp
    src/ASTs/Expr.cpp
    src/ASTs/ExprStmt.cpp
    src/ASTs/FloatExpr.cpp
    src/ASTs/FloatLiteral.cpp
    src/ASTs/FloatType.cpp
    src/ASTs/ForStmt.cpp
    src/ASTs/FuncDecl.cpp
    src/ASTs/GlobalVarDecl.cpp
    src/ASTs/Ident.cpp
    src/ASTs/IfStmt.cpp
    src/ASTs/IntExpr.cpp
    src/ASTs/IntLiteral.cpp
    src/ASTs/IntType.cpp
    src/ASTs/LocalVarDecl.cpp
    src/ASTs/Operator.cpp
    src/ASTs/ParaDecl.cpp
    src/ASTs/ParaList.cpp
    src/ASTs/Program.cpp
    src/ASTs/ReturnStmt.cpp
    src/ASTs/SimpleVar.cpp
    src/ASTs/Stmt.cpp
    src/ASTs/StmtList.cpp
    src/ASTs/StringExpr.cpp
    src/ASTs/StringLiteral.cpp
    src/ASTs/StringType.cpp
    src/ASTs/Terminal.cpp
    src/ASTs/Type.cpp
    src/ASTs/UnaryExpr.cpp
    src/ASTs/Var.cpp
    src/ASTs/VarExpr.cpp
    src/ASTs/VoidType.cpp
    src/ASTs/WhileStmt.cpp
)
target_include_directories(compiler PRIVATE include src)
target_compile_options(compiler PRIVATE -Wall -Wextra -Wpedantic)
