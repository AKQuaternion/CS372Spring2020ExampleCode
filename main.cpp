#include <iostream>
using std::cout;
using std::endl;

#include "Expression.hpp"
using std::make_unique;
using std::unique_ptr;

#include "StoreByReference.hpp"
#include "StoreByPointer.hpp"

#include "moderncppexamples.hpp"

#include "Observer.hpp"
using std::make_shared;
#include "Subject.hpp"\

#include "Armor.hpp"

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

   auto compClone = comp->clone();

   auto squareIt = make_unique<DivideExpression>(move(comp),move(compClone));

   cout << "The value of " << squareIt->toString() << " is " << squareIt->evaluate()
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

void demonstrateObserver() {
   Subject s;

   auto co = make_shared<CoutObserver>();
   auto co2 = make_shared<CoutObserver>();
   auto bo = make_shared<BarGraphObserver>();
   s.attach(co);
   s.attach(co);
   s.attach(co2);
   s.attach(bo);

   s.setN(13);
   s.detach(co2);
   s.setN(67);
   s.detach(co);
   s.setN(1);
}

void demonstrateDecorator() {
   unique_ptr<ArmorComponent> plate = make_unique<PlateArmor>();
   cout << plate->description() << endl;
   unique_ptr<ArmorComponent> rustyPlate = make_unique<RustyDecorator>(move(plate));
   cout << rustyPlate->description() << endl;
   unique_ptr<ArmorComponent> rustyrustyPlate = make_unique<RustyDecorator>(move(rustyPlate));
   cout << rustyrustyPlate->description() << endl;
}

int main() {
//    demonstrateStoreByReference();
//    demonstrateStoreByPointer();
//   demonstrateExpressions();
//   demonstrateObserver();
   demonstrateDecorator();

   return 0;
}

// Possible extensions:
// Refactor so that there isn't so much duplicated code in binary expressions
