#include "TreeCopier.hpp"

Expression* TreeCopier::transformNumber(Number const* number) {
    return new Number(number->value());
}

Expression* TreeCopier::transformBinaryOperation(BinaryOperation const* binop) {
    Expression* left = binop->left()->transform(this);
    Expression* right = binop->right()->transform(this);
    return new BinaryOperation(left, binop->operation(), right);
}

Expression* TreeCopier::transformFunctionCall(FunctionCall const* fcall) {
    Expression* arg = fcall->arg()->transform(this);
    return new FunctionCall(fcall->name(), arg);
}

Expression* TreeCopier::transformVariable(Variable const* var) {
    return new Variable(var->name());
}