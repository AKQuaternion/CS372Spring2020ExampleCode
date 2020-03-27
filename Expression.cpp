//
// Created by Chris Hartman on 3/23/20.
//

#include "Expression.hpp"

SumExpression::SumExpression(std::unique_ptr<Expression> &&lhs,
                             std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)}
{}

std::string SumExpression::print() const {
  return _lhs->print() + " + " +_rhs->print();

  return "";
}

int SumExpression::evaluate() const {
  return _lhs->evaluate() + _rhs->evaluate();
}

MinusExpression::MinusExpression(std::unique_ptr<Expression> &&lhs,
                                 std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)}
{}

std::string MinusExpression::print() const {
  return _lhs->print() + " - " +_rhs->print();

}

int MinusExpression::evaluate() const {
  return _lhs->evaluate() - _rhs->evaluate();
}

TimesExpression::TimesExpression(std::unique_ptr<Expression> &&lhs,
                                 std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)}
{}

int TimesExpression:: evaluate() const {
  return _lhs->evaluate() * _rhs->evaluate();
}

std::string TimesExpression::print() const {
  return _lhs->print() + " * " +_rhs->print();

}

std::string DivideExpression::print() const {
  return _lhs->print() + " / " +_rhs->print();
}

int DivideExpression::evaluate() const {
  return _lhs->evaluate() + _rhs->evaluate();
}

DivideExpression::DivideExpression(std::unique_ptr<Expression> &&lhs,
                                   std::unique_ptr<Expression> &&rhs)
    : _lhs{move(lhs)}, _rhs{move(rhs)}
{}

std::string NumberExpression::print() const {
  return std::to_string(_number);
}

NumberExpression::NumberExpression(int number) : _number(number)
{}

int NumberExpression::evaluate() const {
  return _number;
}
