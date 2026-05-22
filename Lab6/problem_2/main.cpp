#include "FoldOptimizer.hpp"
#include <iostream>

int main() {
    Number* n32 = new Number(32.0);
    Number* n16 = new Number(16.0);
    BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
    FunctionCall* callSqrt = new FunctionCall("sqrt", minus);
    Variable* var = new Variable("x");
    BinaryOperation* mult = new BinaryOperation(var, BinaryOperation::MUL, callSqrt);
    FunctionCall* callAbs = new FunctionCall("abs", mult);
    
    std::cout << "Before folding: " << callAbs->evaluate() << std::endl;
    
    FoldOptimizer optimizer;
    Expression* optimized = callAbs->transform(&optimizer);
    
    std::cout << "After folding: " << optimized->evaluate() << std::endl;
    
    BinaryOperation* complex = new BinaryOperation(
        new Number(5.0),
        BinaryOperation::MUL,
        new BinaryOperation(
            new Number(2.0),
            BinaryOperation::PLUS,
            new Number(3.0)
        )
    );
    
    std::cout << "\nComplex test:" << std::endl;
    std::cout << "5 * (2 + 3) = " << complex->evaluate() << std::endl;
    
    Expression* foldedComplex = complex->transform(&optimizer);
    Number* result = dynamic_cast<Number*>(foldedComplex);
    if (result) {
        std::cout << "Folded to constant: " << result->value() << std::endl;
    }
    
    delete callAbs;
    delete optimized;
    delete complex;
    delete foldedComplex;
    
    return 0;
}