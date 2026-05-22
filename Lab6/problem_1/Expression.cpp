#include "Expression.hpp"
#include <cmath>
#include <cassert>

Number::Number(double value) : value_(value) {}
double Number::value() const { return value_; }
double Number::evaluate() const { return value_; }
Expression* Number::transform(Transformer* tr) const {
    return tr->transformNumber(this);
}

BinaryOperation::BinaryOperation(Expression const* left, int op, Expression const* right)
    : left_(left), op_(op), right_(right) {
    assert(left_ && right_);
}

BinaryOperation::~BinaryOperation() {
    delete left_;
    delete right_;
}

double BinaryOperation::evaluate() const {
    double left = left_->evaluate();
    double right = right_->evaluate();
    switch (op_) {
        case PLUS: return left + right;
        case MINUS: return left - right;
        case DIV: return left / right;
        case MUL: return left * right;
        default: return 0.0;
    }
}

Expression* BinaryOperation::transform(Transformer* tr) const {
    return tr->transformBinaryOperation(this);
}

Expression const* BinaryOperation::left() const { return left_; }
Expression const* BinaryOperation::right() const { return right_; }
int BinaryOperation::operation() const { return op_; }

FunctionCall::FunctionCall(std::string const& name, Expression const* arg)
    : name_(name), arg_(arg) {
    assert(arg_);
    assert(name_ == "sqrt" || name_ == "abs");
}

FunctionCall::~FunctionCall() { delete arg_; }

double FunctionCall::evaluate() const {
    if (name_ == "sqrt")
        return sqrt(arg_->evaluate());
    else
        return fabs(arg_->evaluate());
}

Expression* FunctionCall::transform(Transformer* tr) const {
    return tr->transformFunctionCall(this);
}

std::string const& FunctionCall::name() const { return name_; }
Expression const* FunctionCall::arg() const { return arg_; }

Variable::Variable(std::string const& name) : name_(name) {}
std::string const& Variable::name() const { return name_; }
double Variable::evaluate() const { return 0.0; }
Expression* Variable::transform(Transformer* tr) const {
    return tr->transformVariable(this);
}