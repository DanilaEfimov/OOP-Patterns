#ifndef FOLD_OPTIMIZER_HPP
#define FOLD_OPTIMIZER_HPP

#include "Expression.hpp"

struct FoldOptimizer : Transformer {
    Expression* transformNumber(Number const* number) override;
    Expression* transformBinaryOperation(BinaryOperation const* binop) override;
    Expression* transformFunctionCall(FunctionCall const* fcall) override;
    Expression* transformVariable(Variable const* var) override;
    
private:
    bool isConstant(Expression const* expr) const;
    double getConstantValue(Expression const* expr) const;
};

#endif