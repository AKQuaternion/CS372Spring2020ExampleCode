//
// Created by Chris Hartman on 3/23/20.
//

#ifndef CS372SPRING2020EXAMPLECODE_EXPRESSION_HPP
#define CS372SPRING2020EXAMPLECODE_EXPRESSION_HPP
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::move;
#include <iostream>
using std::cout;

// E → E + E
// E → E – E
// E → E * E
// E → E / E
// E → [number]

class Expression {
public:
  virtual ~Expression() = default;
  virtual void print() const=0;
  virtual int evaluate() const=0;
};

class SumExpression : public Expression {
public:
  SumExpression(unique_ptr<Expression> &&lhs , unique_ptr<Expression> &&rhs);
  void print() const override;
  int evaluate() const override;;
private:
  unique_ptr<Expression> _lhs;
  unique_ptr<Expression> _rhs;
};

class MinusExpression : public Expression {
public:
  MinusExpression(unique_ptr<Expression> &&lhs , unique_ptr<Expression> &&rhs);
  void print() const override;
  int evaluate() const override;;
private:
  unique_ptr<Expression> _lhs;
  unique_ptr<Expression> _rhs;
};

class TimesExpression : public Expression {
public:
  TimesExpression(unique_ptr<Expression> &&lhs , unique_ptr<Expression> &&rhs);
  void print() const override;
  int evaluate() const override;;
private:
  unique_ptr<Expression> _lhs;
  unique_ptr<Expression> _rhs;
};

class DivideExpression : public Expression {
public:
  DivideExpression(unique_ptr<Expression> &&lhs , unique_ptr<Expression> &&rhs);
  void print() const override;
  int evaluate() const override;;
private:
  unique_ptr<Expression> _lhs;
  unique_ptr<Expression> _rhs;
};

class NumberExpression : public Expression {
public:
  NumberExpression(int number);
  void print() const override;
  int evaluate() const override {
    return _number;
  }
private:
  int _number;
};

#endif // CS372SPRING2020EXAMPLECODE_EXPRESSION_HPP
