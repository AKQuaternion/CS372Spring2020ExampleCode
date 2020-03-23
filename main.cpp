#include "moderncppexamples.hpp"
#include "Expression.hpp"

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
