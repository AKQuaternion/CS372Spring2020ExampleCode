//
// Created by Chris Hartman on 4/10/20.
//

#include "Armor.hpp"

std::string ArmorDecorator::description() const {
   return _wrappee->description();
}
