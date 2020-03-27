//
// Created by Chris Hartman on 3/23/20.
//

#include "Expression.hpp"

SumExpression::SumExpression(std::unique_ptr<Expression> &&lhs,
                             std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)} {}

std::string SumExpression::toString() const {
  return _lhs->toString() + " + " + _rhs->toString();

  return "";
}

int SumExpression::evaluate() const {
  return _lhs->evaluate() + _rhs->evaluate();
}

MinusExpression::MinusExpression(std::unique_ptr<Expression> &&lhs,
                                 std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)} {}

std::string MinusExpression::toString() const {
  return _lhs->toString() + " - " + _rhs->toString();
}

int MinusExpression::evaluate() const {
  return _lhs->evaluate() - _rhs->evaluate();
}

TimesExpression::TimesExpression(std::unique_ptr<Expression> &&lhs,
                                 std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)} {}

int TimesExpression::evaluate() const {
  return _lhs->evaluate() * _rhs->evaluate();
}

std::string TimesExpression::toString() const {
  return _lhs->toString() + " * " + _rhs->toString();
}

std::string DivideExpression::toString() const {
  return _lhs->toString() + " / " + _rhs->toString();
}

int DivideExpression::evaluate() const {
  return _lhs->evaluate() + _rhs->evaluate();
}

DivideExpression::DivideExpression(std::unique_ptr<Expression> &&lhs,
                                   std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)} {}

std::string NumberExpression::toString() const {
  return std::to_string(_number);
}

NumberExpression::NumberExpression(int number) : _number(number) {}

int NumberExpression::evaluate() const { return _number; }
