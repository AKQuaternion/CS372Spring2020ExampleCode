//
// Created by Chris Hartman on 3/23/20.
//

#ifndef CS372SPRING2020EXAMPLECODE_EXPRESSION_HPP
#define CS372SPRING2020EXAMPLECODE_EXPRESSION_HPP
#include <iostream>
#include <memory>
#include <string>

// E → E + E
// E → E – E
// E → E * E
// E → E / E
// E → [number]

class Expression {
public:
   virtual ~Expression() = default;
   Expression() = default;
   Expression(const Expression &) = default;
   virtual std::unique_ptr<Expression> clone() const = 0;
   virtual std::string toString() const = 0;
   virtual int evaluate() const = 0;
};

class SumExpression : public Expression {
public:
   SumExpression(std::unique_ptr<Expression> &&lhs,
                 std::unique_ptr<Expression> &&rhs);
   std::unique_ptr<Expression> clone() const override;
   std::string toString() const override;
   int evaluate() const override;

private:
   std::unique_ptr<Expression> _lhs;
   std::unique_ptr<Expression> _rhs;
};

class MinusExpression : public Expression {
public:
   MinusExpression(std::unique_ptr<Expression> &&lhs,
                   std::unique_ptr<Expression> &&rhs);
   std::unique_ptr<Expression> clone() const override;
   std::string toString() const override;
   int evaluate() const override;

private:
   std::unique_ptr<Expression> _lhs;
   std::unique_ptr<Expression> _rhs;
};

class TimesExpression : public Expression {
public:
   TimesExpression(std::unique_ptr<Expression> &&lhs,
                   std::unique_ptr<Expression> &&rhs);
   std::unique_ptr<Expression> clone() const override;
   std::string toString() const override;
   int evaluate() const override;

private:
   std::unique_ptr<Expression> _lhs;
   std::unique_ptr<Expression> _rhs;
};

class DivideExpression : public Expression {
public:
   DivideExpression(std::unique_ptr<Expression> &&lhs,
                    std::unique_ptr<Expression> &&rhs);
   std::unique_ptr<Expression> clone() const override;
   std::string toString() const override;
   int evaluate() const override;

private:
   std::unique_ptr<Expression> _lhs;
   std::unique_ptr<Expression> _rhs;
};

class NumberExpression : public Expression {
public:
   NumberExpression(int number);
   std::unique_ptr<Expression> clone() const override;
   std::string toString() const override;
   int evaluate() const override;

private:
   int _number;
};

#endif  // CS372SPRING2020EXAMPLECODE_EXPRESSION_HPP
