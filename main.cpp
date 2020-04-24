#include <iostream>
using std::cout;
using std::endl;

#include "Expression.hpp"
using std::make_unique;
using std::unique_ptr;

#include "StoreByPointer.hpp"
#include "StoreByReference.hpp"

#include "moderncppexamples.hpp"

#include "Observer.hpp"
using std::make_shared;
#include "Subject.hpp"

#include "Armor.hpp"

#include "Command.hpp"
#include "HomeAutomationComponent.hpp"
using std::shared_ptr;
using std::vector;

#include "Composite.hpp"

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

   auto squareIt = make_unique<DivideExpression>(move(comp), move(compClone));

   cout << "The value of " << squareIt->toString() << " is "
        << squareIt->evaluate() << std::endl;
}

void demonstrateStoreByReference() {
   cout << "\nDemonstrating store by reference:\n";
   RepairFacility downtown("456 1st Avenue");
   RepairFacility hillside("123 Oak St.");

   RobotR kim("Kim", downtown);
   RobotR joe("Joseph", hillside);

   kim.repair();
   joe.repair();
}

void demonstrateStoreByPointer() {
   cout << "\nDemonstrating store by pointer:\n";
   RepairFacility downtown("456 1st Avenue");
   RepairFacility hillside("123 Oak St.");

   RobotP kim("Kim", &downtown);
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
   cout << plate->description() << " has AC " << plate->getAC() << endl;
   unique_ptr<ArmorComponent> rustyPlate =
      make_unique<RustyDecorator>(move(plate));
   cout << rustyPlate->description() << " has AC " << rustyPlate->getAC()
        << endl;
   unique_ptr<ArmorComponent> rustyrustyPlate =
      make_unique<RustyDecorator>(move(rustyPlate));
   cout << rustyrustyPlate->description() << " has AC "
        << rustyrustyPlate->getAC() << endl;
   unique_ptr<ArmorComponent> magicLeather =
      make_unique<MagicDecorator>(make_unique<LeatherArmor>());
   cout << magicLeather->description() << " has AC " << magicLeather->getAC()
        << endl;
}

[[noreturn]] void demonstrateCommand() {
   //   SayHiCommand x;
   //   x.execute();
   //
   //   auto f = make_shared<FanObject>();
   //   f->on();
   //   f->off();
   auto l = make_shared<LightObject>();
   //   l->on();
   //   l->off();
   //   auto s = make_shared<StereoObject>();
   //   s->on();
   //   s->off();
   //
   //   HACOnCommand fanOnCommand(f);
   //   fanOnCommand.execute();

   vector<shared_ptr<Command>> v(10, make_shared<NullCommand>());
   v[0] = make_shared<SayHiCommand>();
   v[1] = make_shared<HACOnCommand>(l);
   v[2] = make_shared<HACOffCommand>(l);
   v[3] = make_shared<VoidFunctionCommand>(demonstrateDecorator);
   v[4] = make_shared<VoidFunctionCommand>([]() { cout << "It's Friday!\n"; });
   v[9] = make_shared<ExitCommand>();
   v[5] = make_shared<MacroCommand>(
      vector<shared_ptr<Command>>({v[0], v[1], v[2], v[3], v[4]}));
   auto doorHAC = make_shared<DoorAdapter>(make_shared<HouseDoor>());
   v[6] = make_shared<HACOnCommand>(doorHAC);
   while (true) {
      cout << "What button? ";
      unsigned int button;
      std::cin >> button;
      v[button]->execute();
   }

   //   ExitCommand ex;
   //   ex.execute();
}

void demonstrateComposite() {
       auto f1 = make_unique<File>("f1", 1);
   cout << f1->getName() << " " << f1->getSize() << endl;
   auto folder1 = make_unique<Folder>("folder1");
   folder1->add(move(f1));
   cout << folder1->getName() << " " << folder1->getSize() << endl;
   folder1->add(make_unique<File>("f2", 2));
   folder1->add(make_unique<File>("f3", 3));
   cout << folder1->getName() << " " << folder1->getSize() << endl;
   folder1->remove("f2");
   cout << folder1->getName() << " " << folder1->getSize() << endl;
}

int main() {
   //   modernCppExamples();
   //   demonstrateStoreByReference();
   //   demonstrateStoreByPointer();
   //   demonstrateExpressions();
   //   demonstrateObserver();
   //   demonstrateDecorator();
//   demonstrateCommand();
demonstrateComposite();
   return 0;
}

// Possible extensions:
// Refactor so that there isn't so much duplicated code in binary expressions
