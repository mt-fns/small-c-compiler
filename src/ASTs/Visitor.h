#pragma once

#include <any>

class Arg;
class ArgList;
class ArrayExpr;
class ArrayExprList;
class ArrayInitExpr;
class ArrayType;
class AssignExpr;
class BinaryExpr;
class BooleanExpr;
class BooleanLiteral;
class BooleanType;
class BreakStmt;
class CallExpr;
class CompoundStmt;
class ContinueStmt;
class DeclList;
class EmptyArgList;
class EmptyArrayExprList;
class EmptyCompStmt;
class EmptyDeclList;
class EmptyExpr;
class EmptyParaList;
class EmptyStmt;
class EmptyStmtList;
class ErrorType;
class ExprStmt;
class FloatExpr;
class FloatLiteral;
class FloatType;
class ForStmt;
class FuncDecl;
class GlobalVarDecl;
class Ident;
class IfStmt;
class IntExpr;
class IntLiteral;
class IntType;
class LocalVarDecl;
class Operator;
class ParaDecl;
class ParaList;
class Program;
class ReturnStmt;
class SimpleVar;
class StmtList;
class StringExpr;
class StringLiteral;
class StringType;
class UnaryExpr;
class VarExpr;
class VoidType;
class WhileStmt;

class Visitor {
    public:
        virtual ~Visitor() = default;

        // Programs
        virtual std::any visitProgram(Program* ast, std::any o) = 0;

        // Lists for denoting the null reference
        virtual std::any visitEmptyDeclList(EmptyDeclList* ast, std::any o) = 0;
        virtual std::any visitEmptyStmtList(EmptyStmtList* ast, std::any o) = 0;
        virtual std::any visitEmptyArrayExprList(EmptyArrayExprList* ast, std::any o) = 0;
        virtual std::any visitEmptyParaList(EmptyParaList* ast, std::any o) = 0;
        virtual std::any visitEmptyArgList(EmptyArgList* ast, std::any o) = 0;

        // Declarations
        virtual std::any visitDeclList(DeclList* ast, std::any o) = 0;
        virtual std::any visitFuncDecl(FuncDecl* ast, std::any o) = 0;
        virtual std::any visitGlobalVarDecl(GlobalVarDecl* ast, std::any o) = 0;
        virtual std::any visitLocalVarDecl(LocalVarDecl* ast, std::any o) = 0;

        // Stmts
        virtual std::any visitStmtList(StmtList* ast, std::any o) = 0;
        virtual std::any visitIfStmt(IfStmt* ast, std::any o) = 0;
        virtual std::any visitWhileStmt(WhileStmt* ast, std::any o) = 0;
        virtual std::any visitForStmt(ForStmt* ast, std::any o) = 0;
        virtual std::any visitBreakStmt(BreakStmt* ast, std::any o) = 0;
        virtual std::any visitContinueStmt(ContinueStmt* ast, std::any o) = 0;
        virtual std::any visitReturnStmt(ReturnStmt* ast, std::any o) = 0;
        virtual std::any visitCompoundStmt(CompoundStmt* ast, std::any o) = 0;
        virtual std::any visitExprStmt(ExprStmt* ast, std::any o) = 0;
        virtual std::any visitEmptyCompStmt(EmptyCompStmt* ast, std::any o) = 0;
        virtual std::any visitEmptyStmt(EmptyStmt* ast, std::any o) = 0;

        // Expressions
        virtual std::any visitIntExpr(IntExpr* ast, std::any o) = 0;
        virtual std::any visitFloatExpr(FloatExpr* ast, std::any o) = 0;
        virtual std::any visitBooleanExpr(BooleanExpr* ast, std::any o) = 0;
        virtual std::any visitStringExpr(StringExpr* ast, std::any o) = 0;
        virtual std::any visitUnaryExpr(UnaryExpr* ast, std::any o) = 0;
        virtual std::any visitBinaryExpr(BinaryExpr* ast, std::any o) = 0;
        virtual std::any visitArrayInitExpr(ArrayInitExpr* ast, std::any o) = 0;
        virtual std::any visitArrayExprList(ArrayExprList* ast, std::any o) = 0;
        virtual std::any visitArrayExpr(ArrayExpr* ast, std::any o) = 0;
        virtual std::any visitVarExpr(VarExpr* ast, std::any o) = 0;
        virtual std::any visitCallExpr(CallExpr* ast, std::any o) = 0;
        virtual std::any visitAssignExpr(AssignExpr* ast, std::any o) = 0;
        virtual std::any visitEmptyExpr(EmptyExpr* ast, std::any o) = 0;

        // Literals and identifiers
        virtual std::any visitIntLiteral(IntLiteral* ast, std::any o) = 0;
        virtual std::any visitFloatLiteral(FloatLiteral* ast, std::any o) = 0;
        virtual std::any visitBooleanLiteral(BooleanLiteral* ast, std::any o) = 0;
        virtual std::any visitStringLiteral(StringLiteral* ast, std::any o) = 0;
        virtual std::any visitIdent(Ident* ast, std::any o) = 0;
        virtual std::any visitOperator(Operator* ast, std::any o) = 0;

        // Parameters
        virtual std::any visitParaList(ParaList* ast, std::any o) = 0;
        virtual std::any visitParaDecl(ParaDecl* ast, std::any o) = 0;

        // Arguments
        virtual std::any visitArgList(ArgList* ast, std::any o) = 0;
        virtual std::any visitArg(Arg* ast, std::any o) = 0;

        // Types
        virtual std::any visitVoidType(VoidType* ast, std::any o) = 0;
        virtual std::any visitBooleanType(BooleanType* ast, std::any o) = 0;
        virtual std::any visitIntType(IntType* ast, std::any o) = 0;
        virtual std::any visitFloatType(FloatType* ast, std::any o) = 0;
        virtual std::any visitStringType(StringType* ast, std::any o) = 0;
        virtual std::any visitArrayType(ArrayType* ast, std::any o) = 0;
        virtual std::any visitErrorType(ErrorType* ast, std::any o) = 0;

        // Variables
        virtual std::any visitSimpleVar(SimpleVar* ast, std::any o) = 0;
};
