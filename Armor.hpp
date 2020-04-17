#ifndef ARMOR_HPP
#define ARMOR_HPP

#include <string>
#include <memory>

class ArmorComponent {
public:
    virtual ~ArmorComponent() = default;
    [[nodiscard]] virtual std::string description() const=0 ;
    [[nodiscard]] virtual int getAC() const=0 ;
};

class PlateArmor : public ArmorComponent {
   [[nodiscard]] std::string description() const override
   {
      return "Plate Mail";
   }

   [[nodiscard]] int getAC() const override
   {
      return 10;
   }
};

class LeatherArmor : public ArmorComponent {
   [[nodiscard]] std::string description() const override
   {
      return "Leather Armor";
   }

   [[nodiscard]]int getAC() const override
   {
      return 3;
   }
};


class ArmorDecorator : public ArmorComponent {
public:
    explicit ArmorDecorator(std::unique_ptr<ArmorComponent> wrappee)
    :_wrappee(std::move(wrappee))
    {}
    [[nodiscard]] std::string description() const override = 0;

    [[nodiscard]] int getAC() const override {
        return _wrappee->getAC();  //bad, implements a virtual function which derived clases will override
    }
private:
    std::unique_ptr<ArmorComponent> _wrappee;
};

class RustyDecorator : public ArmorDecorator {
public:
   using ArmorDecorator::ArmorDecorator;
   [[nodiscard]] std::string description() const override {
      return "Rusty " + ArmorDecorator::description();
   }
   [[nodiscard]] int getAC() const override {
      return ArmorDecorator::getAC() - 3;
   }
};


class MagicDecorator : public ArmorDecorator {
public:
   using ArmorDecorator::ArmorDecorator;
   [[nodiscard]] std::string description() const override {
      return "Magic " + ArmorDecorator::description();
   }
   [[nodiscard]] int getAC() const override {
      return ArmorDecorator::getAC() + 1;
   }
};


#endif
