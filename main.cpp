#include <iostream>
using std::cout;
using std::endl;

#include "moderncppexamples.hpp"
#include "Expression.hpp"
using std::unique_ptr;
using std::make_unique;

int main() {
  unique_ptr<Expression> fifteen = make_unique<NumberExpression>(15);

  cout <<  fifteen->print() << std::endl;
  unique_ptr<Expression> four = make_unique<NumberExpression>(4);
  unique_ptr<Expression> s = make_unique<SumExpression>(move(fifteen),move(four));

  cout << s->print() << "\n";
  cout << "The value of s is " << s->evaluate() << std::endl;

  unique_ptr<Expression> comp = make_unique<TimesExpression>(
      move(s),
      make_unique<MinusExpression>(make_unique<NumberExpression>(13),
          make_unique<NumberExpression>(9))
      );

  cout << "The value of " << comp->print() << " is " << comp->evaluate() << std::endl;
  return 0;
}

// Possible extensions
// Factory for making expressions
// print() should really be toString()
// Refactor so that there isn't so much duplicated code in binary expressions
