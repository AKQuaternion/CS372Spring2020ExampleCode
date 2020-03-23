//
// Created by Chris Hartman on 3/23/20.
//

#include "Expression.hpp"

SumExpression::SumExpression(unique_ptr<Expression> &&lhs,
                             unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)}
{}
void SumExpression::print() const {
  _lhs->print();
  cout << " + ";
  _rhs->print();
}
int SumExpression::evaluate() const {
  return _lhs->evaluate() + _rhs->evaluate();
}
MinusExpression::MinusExpression(unique_ptr<Expression> &&lhs,
                                 unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)}
{}
void MinusExpression::print() const {
  _lhs->print();
  cout << " - ";
  _rhs->print();
}
int MinusExpression::evaluate() const {
  return _lhs->evaluate() - _rhs->evaluate();
}
TimesExpression::TimesExpression(unique_ptr<Expression> &&lhs,
                                 unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)}
{}
int TimesExpression:: evaluate() const {
  return _lhs->evaluate() * _rhs->evaluate();
}
void TimesExpression::print() const {
  _lhs->print();
  cout << " * ";
  _rhs->print();
}
void DivideExpression::print() const {
  _lhs->print();
  cout << " + ";
  _rhs->print();
}
int DivideExpression::evaluate() const {
  return _lhs->evaluate() + _rhs->evaluate();
}
DivideExpression::DivideExpression(unique_ptr<Expression> &&lhs,
                                   unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)}
{}
void NumberExpression::print() const {
  cout << _number;
}
NumberExpression::NumberExpression(int number) : _number(number)
{}
