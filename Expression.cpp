//
// Created by Chris Hartman on 3/23/20.
//

#include "Expression.hpp"

SumExpression::SumExpression(std::unique_ptr<Expression> &&lhs,
                             std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)} {}

std::unique_ptr<Expression> SumExpression::clone() const {
   return std::make_unique<SumExpression>(_lhs->clone(),_rhs->clone());
}

std::string SumExpression::toString() const {
  return _lhs->toString() + " + " + _rhs->toString();
}

int SumExpression::evaluate() const {
  return _lhs->evaluate() + _rhs->evaluate();
}

MinusExpression::MinusExpression(std::unique_ptr<Expression> &&lhs,
                                 std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)} {}

std::unique_ptr<Expression> MinusExpression::clone() const {
   return std::make_unique<MinusExpression>(_lhs->clone(),_rhs->clone());
}

std::string MinusExpression::toString() const {
  return _lhs->toString() + " - " + _rhs->toString();
}

int MinusExpression::evaluate() const {
  return _lhs->evaluate() - _rhs->evaluate();
}

TimesExpression::TimesExpression(std::unique_ptr<Expression> &&lhs,
                                 std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)} {}

std::unique_ptr<Expression> TimesExpression::clone() const {
   return std::make_unique<TimesExpression>(_lhs->clone(),_rhs->clone());
}

std::string TimesExpression::toString() const {
   return _lhs->toString() + " * " + _rhs->toString();
}

int TimesExpression::evaluate() const {
  return _lhs->evaluate() * _rhs->evaluate();
}

DivideExpression::DivideExpression(std::unique_ptr<Expression> &&lhs,
                                   std::unique_ptr<Expression> &&rhs)
   : _lhs{move(lhs)}, _rhs{move(rhs)} {}

std::unique_ptr<Expression> DivideExpression::clone() const {
   return std::make_unique<DivideExpression>(_lhs->clone(),_rhs->clone());
}

std::string DivideExpression::toString() const {
  return _lhs->toString() + " / " + _rhs->toString();
}

int DivideExpression::evaluate() const {
  return _lhs->evaluate() / _rhs->evaluate();
}

NumberExpression::NumberExpression(int number) : _number(number) {}

std::unique_ptr<Expression> NumberExpression::clone() const {
   return std::make_unique<NumberExpression>(*this); //use the copy constructor
}

std::string NumberExpression::toString() const {
   return std::to_string(_number);
}

int NumberExpression::evaluate() const { return _number; }
