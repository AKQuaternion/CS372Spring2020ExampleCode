#include "moderncppexamples.hpp"
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
  SumExpression(unique_ptr<Expression> &&lhs , unique_ptr<Expression> &&rhs)
      : _lhs{move(lhs)}, _rhs{move(rhs)}
  {}
  void print() const override {
    _lhs->print();
    cout << " + ";
    _rhs->print();
  }
  int evaluate() const override {
    return _lhs->evaluate() + _rhs->evaluate();
  };
private:
  unique_ptr<Expression> _lhs;
  unique_ptr<Expression> _rhs;
};

class MinusExpression : public Expression {
public:
  MinusExpression(unique_ptr<Expression> &&lhs , unique_ptr<Expression> &&rhs)
      : _lhs{move(lhs)}, _rhs{move(rhs)}
  {}
  void print() const override {
    _lhs->print();
    cout << " - ";
    _rhs->print();
  }
  int evaluate() const override {
    return _lhs->evaluate() - _rhs->evaluate();
  };
private:
  unique_ptr<Expression> _lhs;
  unique_ptr<Expression> _rhs;
};

class TimesExpression : public Expression {
public:
  TimesExpression(unique_ptr<Expression> &&lhs , unique_ptr<Expression> &&rhs)
      : _lhs{move(lhs)}, _rhs{move(rhs)}
  {}
  void print() const override {
    _lhs->print();
    cout << " * ";
    _rhs->print();
  }
  int evaluate() const override {
    return _lhs->evaluate() * _rhs->evaluate();
  };
private:
  unique_ptr<Expression> _lhs;
  unique_ptr<Expression> _rhs;
};

class DivideExpression : public Expression {
public:
  DivideExpression(unique_ptr<Expression> &&lhs , unique_ptr<Expression> &&rhs)
      : _lhs{move(lhs)}, _rhs{move(rhs)}
  {}
  void print() const override {
    _lhs->print();
    cout << " + ";
    _rhs->print();
  }
  int evaluate() const override {
    return _lhs->evaluate() + _rhs->evaluate();
  };
private:
  unique_ptr<Expression> _lhs;
  unique_ptr<Expression> _rhs;
};

class NumberExpression : public Expression {
public:
  NumberExpression(int number) : _number(number)
  {}
  void print() const override {
    cout << _number;
  }
  int evaluate() const override {
    return _number;
  }
private:
  int _number;
};

int main() {
  unique_ptr<Expression> fifteen = make_unique<NumberExpression>(15);
  unique_ptr<Expression> four = make_unique<NumberExpression>(4);
  unique_ptr<Expression> s = make_unique<SumExpression>(move(fifteen),move(four));

  s->print();
  cout << "\n";
  cout << "The value of s is " << s->evaluate() << std::endl;

  unique_ptr<Expression> comp = make_unique<TimesExpression>(
      move(s),
      make_unique<MinusExpression>(make_unique<NumberExpression>(13),
          make_unique<NumberExpression>(9))
      );

  cout << "The value of ";
  comp->print();
  cout << " is " << comp->evaluate() << std::endl;
  return 0;
}
