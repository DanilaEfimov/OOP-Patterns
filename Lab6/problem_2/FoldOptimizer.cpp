#include "FoldOptimizer.hpp"
#include <cmath>

Expression* FoldOptimizer::transformNumber(Number const* number) {
    return new Number(number->value());
}

Expression* FoldOptimizer::transformBinaryOperation(BinaryOperation const* binop) {
    Expression* newLeft = binop->left()->transform(this);
    Expression* newRight = binop->right()->transform(this);
    
    bool leftIsNum = dynamic_cast<Number*>(newLeft) != nullptr;
    bool rightIsNum = dynamic_cast<Number*>(newRight) != nullptr;
    
    if (leftIsNum && rightIsNum) {
        double leftVal = dynamic_cast<Number*>(newLeft)->value();
        double rightVal = dynamic_cast<Number*>(newRight)->value();
        double result = 0;
        
        switch (binop->operation()) {
            case BinaryOperation::PLUS:
                result = leftVal + rightVal;
                break;
            case BinaryOperation::MINUS:
                result = leftVal - rightVal;
                break;
            case BinaryOperation::MUL:
                result = leftVal * rightVal;
                break;
            case BinaryOperation::DIV:
                if (rightVal != 0)
                    result = leftVal / rightVal;
                else
                    return new BinaryOperation(newLeft, binop->operation(), newRight);
                break;
        }
        
        delete newLeft;
        delete newRight;
        return new Number(result);
    }
    
    if (binop->operation() == BinaryOperation::MUL) {
        if (leftIsNum && dynamic_cast<Number*>(newLeft)->value() == 1.0) {
            delete newLeft;
            return newRight;
        }
        if (rightIsNum && dynamic_cast<Number*>(newRight)->value() == 1.0) {
            delete newRight;
            return newLeft;
        }
        if (leftIsNum && dynamic_cast<Number*>(newLeft)->value() == 0.0) {
            delete newRight;
            return newLeft;
        }
        if (rightIsNum && dynamic_cast<Number*>(newRight)->value() == 0.0) {
            delete newLeft;
            return newRight;
        }
    }
    
    if (binop->operation() == BinaryOperation::PLUS) {
        if (leftIsNum && dynamic_cast<Number*>(newLeft)->value() == 0.0) {
            delete newLeft;
            return newRight;
        }
        if (rightIsNum && dynamic_cast<Number*>(newRight)->value() == 0.0) {
            delete newRight;
            return newLeft;
        }
    }
    
    if (binop->operation() == BinaryOperation::MINUS) {
        if (rightIsNum && dynamic_cast<Number*>(newRight)->value() == 0.0) {
            delete newRight;
            return newLeft;
        }
    }
    
    return new BinaryOperation(newLeft, binop->operation(), newRight);
}

Expression* FoldOptimizer::transformFunctionCall(FunctionCall const* fcall) {
    Expression* newArg = fcall->arg()->transform(this);
    
    Number* numArg = dynamic_cast<Number*>(newArg);
    if (numArg) {
        double val = numArg->value();
        double result;
        
        if (fcall->name() == "sqrt") {
            result = sqrt(val);
        } else {
            result = fabs(val);
        }
        
        delete newArg;
        return new Number(result);
    }
    
    return new FunctionCall(fcall->name(), newArg);
}

Expression* FoldOptimizer::transformVariable(Variable const* var) {
    return new Variable(var->name());
}