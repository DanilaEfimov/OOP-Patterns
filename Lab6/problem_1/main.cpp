#include "TreeCopier.hpp"
#include <iostream>

int main() {
    Number* n32 = new Number(32.0);
    Number* n16 = new Number(16.0);
    BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
    FunctionCall* callSqrt = new FunctionCall("sqrt", minus);
    Number* n2 = new Number(2.0);
    BinaryOperation* mult = new BinaryOperation(n2, BinaryOperation::MUL, callSqrt);
    FunctionCall* callAbs = new FunctionCall("abs", mult);
    
    std::cout << callAbs->evaluate() << std::endl;
    
    TreeCopier copier;
    Expression* newExpr = callAbs->transform(&copier);
    
    std::cout << newExpr->evaluate() << std::endl;
    
    delete callAbs;
    delete newExpr;
    
    return 0;
}