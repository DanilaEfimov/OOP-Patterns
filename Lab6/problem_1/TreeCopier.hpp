#ifndef TREE_COPIER_HPP
#define TREE_COPIER_HPP

#include "Expression.hpp"

struct TreeCopier : Transformer {
    Expression* transformNumber(Number const* number) override;
    Expression* transformBinaryOperation(BinaryOperation const* binop) override;
    Expression* transformFunctionCall(FunctionCall const* fcall) override;
    Expression* transformVariable(Variable const* var) override;
};

#endif