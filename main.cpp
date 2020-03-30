#include <iostream>
using std::cout;
using std::endl;

#include "Expression.hpp"
using std::make_unique;
using std::unique_ptr;
#include "StoreByReference.hpp"
#include "StoreByPointer.hpp"

#include "moderncppexamples.hpp"

void demonstrateExpressions() {
  unique_ptr<Expression> fifteen = make_unique<NumberExpression>(15);

  cout << fifteen->toString() << std::endl;
  unique_ptr<Expression> four = make_unique<NumberExpression>(4);
  unique_ptr<Expression> s =
      make_unique<SumExpression>(move(fifteen), move(four));

  cout << s->toString() << "\n";
  cout << "The value of s is " << s->evaluate() << std::endl;

  unique_ptr<Expression> comp = make_unique<TimesExpression>(
      move(s), make_unique<MinusExpression>(make_unique<NumberExpression>(13),
                                            make_unique<NumberExpression>(9)));

  cout << "The value of " << comp->toString() << " is " << comp->evaluate()
       << std::endl;
}


void demonstrateStoreByReference() {
    cout << "\nDemonstrating store by reference:\n";
    RepairFacility downtown("456 1st Avenue");
    RepairFacility hillside("123 Oak St.");

    RobotR kim("Kim",downtown);
    RobotR joe("Joseph", hillside);

    kim.repair();
    joe.repair();
}

void demonstrateStoreByPointer() {
    cout << "\nDemonstrating store by pointer:\n";
    RepairFacility downtown("456 1st Avenue");
    RepairFacility hillside("123 Oak St.");

    RobotP kim("Kim",&downtown);
    RobotP joe("Joseph", &hillside);

    kim.repair();
    joe.repair();

    kim.changeRepairFacility(&hillside);
    kim.repair();
}

int main() {
    demonstrateStoreByReference();
    demonstrateStoreByPointer();
  return 0;
}

// Possible extensions:
// Refactor so that there isn't so much duplicated code in binary expressions
