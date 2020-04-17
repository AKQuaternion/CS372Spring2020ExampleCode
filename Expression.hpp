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
   [[nodiscard]] virtual std::unique_ptr<Expression> clone() const = 0;
   [[nodiscard]] virtual std::string toString() const = 0;
   [[nodiscard]] virtual int evaluate() const = 0;
};

class SumExpression : public Expression {
public:
   SumExpression(std::unique_ptr<Expression> &&lhs,
                 std::unique_ptr<Expression> &&rhs);
   [[nodiscard]] std::unique_ptr<Expression> clone() const override;
   [[nodiscard]] std::string toString() const override;
   [[nodiscard]] int evaluate() const override;

private:
   std::unique_ptr<Expression> _lhs;
   std::unique_ptr<Expression> _rhs;
};

class MinusExpression : public Expression {
public:
   MinusExpression(std::unique_ptr<Expression> &&lhs,
                   std::unique_ptr<Expression> &&rhs);
   [[nodiscard]] std::unique_ptr<Expression> clone() const override;
   [[nodiscard]] std::string toString() const override;
   [[nodiscard]] int evaluate() const override;

private:
   std::unique_ptr<Expression> _lhs;
   std::unique_ptr<Expression> _rhs;
};

class TimesExpression : public Expression {
public:
   TimesExpression(std::unique_ptr<Expression> &&lhs,
                   std::unique_ptr<Expression> &&rhs);
   [[nodiscard]] std::unique_ptr<Expression> clone() const override;
   [[nodiscard]] std::string toString() const override;
   [[nodiscard]] int evaluate() const override;

private:
   std::unique_ptr<Expression> _lhs;
   std::unique_ptr<Expression> _rhs;
};

class DivideExpression : public Expression {
public:
   DivideExpression(std::unique_ptr<Expression> &&lhs,
                    std::unique_ptr<Expression> &&rhs);
   [[nodiscard]] std::unique_ptr<Expression> clone() const override;
   [[nodiscard]] std::string toString() const override;
   [[nodiscard]] int evaluate() const override;

private:
   std::unique_ptr<Expression> _lhs;
   std::unique_ptr<Expression> _rhs;
};

class NumberExpression : public Expression {
public:
   NumberExpression(int number); //NOLINT
   [[nodiscard]] std::unique_ptr<Expression> clone() const override;
   [[nodiscard]] std::string toString() const override;
   [[nodiscard]] int evaluate() const override;

private:
   int _number;
};

#endif  // CS372SPRING2020EXAMPLECODE_EXPRESSION_HPP
