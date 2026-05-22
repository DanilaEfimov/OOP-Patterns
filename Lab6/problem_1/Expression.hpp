#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <string>

struct Transformer;
struct Number;
struct BinaryOperation;
struct FunctionCall;
struct Variable;

struct Expression {
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
    virtual Expression* transform(Transformer* tr) const = 0;
};

struct Transformer {
    virtual ~Transformer() {}
    virtual Expression* transformNumber(Number const*) = 0;
    virtual Expression* transformBinaryOperation(BinaryOperation const*) = 0;
    virtual Expression* transformFunctionCall(FunctionCall const*) = 0;
    virtual Expression* transformVariable(Variable const*) = 0;
};

struct Number : Expression {
    Number(double value);
    double value() const;
    double evaluate() const override;
    Expression* transform(Transformer* tr) const override;
private:
    double value_;
};

struct BinaryOperation : Expression {
    enum {
        PLUS = '+',
        MINUS = '-',
        DIV = '/',
        MUL = '*'
    };
    
    BinaryOperation(Expression const* left, int op, Expression const* right);
    ~BinaryOperation();
    double evaluate() const override;
    Expression* transform(Transformer* tr) const override;
    Expression const* left() const;
    Expression const* right() const;
    int operation() const;
private:
    Expression const* left_;
    Expression const* right_;
    int op_;
};

struct FunctionCall : Expression {
    FunctionCall(std::string const& name, Expression const* arg);
    ~FunctionCall();
    double evaluate() const override;
    Expression* transform(Transformer* tr) const override;
    std::string const& name() const;
    Expression const* arg() const;
private:
    std::string const name_;
    Expression const* arg_;
};

struct Variable : Expression {
    Variable(std::string const& name);
    std::string const& name() const;
    double evaluate() const override;
    Expression* transform(Transformer* tr) const override;
private:
    std::string const name_;
};

#endif