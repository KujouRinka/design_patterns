#ifndef DATA_STRUCTURES_AND_ALGORITHM_VISITOR_H
#define DATA_STRUCTURES_AND_ALGORITHM_VISITOR_H

using Watt = unsigned int;
using Currency = unsigned int;

class EquipmentVisitor;

// Element
class Equipment {
public:
    virtual ~Equipment() { delete[]_name; }
    const char *Name() { return _name; }

    virtual void accept(EquipmentVisitor &visitor) = 0;

    virtual Watt power() = 0;
    virtual Currency netPrice() = 0;
    virtual Currency discountPrice() = 0;

protected:
    Equipment(const char *);

private:
    const char *_name;
};

class FloppyDisk : public Equipment {
public:
    FloppyDisk() : Equipment("FloppyDisk") {};

    void accept(EquipmentVisitor &visitor) override;
    Watt power() override { return 10; };
    Currency netPrice() override { return 39; };
    Currency discountPrice() override { return 29; };
};

class Card : public Equipment {
public:
    Card() : Equipment("Card") {}

    void accept(EquipmentVisitor &visitor) override;
    Watt power() override { return 5; };
    Currency netPrice() override { return 9; };
    Currency discountPrice() override { return 5; };
};

class Bus : public Equipment {
public:
    Bus() : Equipment("Equipment") {}

    void accept(EquipmentVisitor &visitor) override;
    Watt power() override { return 300; };
    Currency netPrice() override { return 199; };
    Currency discountPrice() override { return 169; };
};

#include <vector>

class Composite : public Equipment {
public:
    Composite(std::initializer_list<Equipment *> list) : Equipment("Composite"), _child(list) {}

    void accept(EquipmentVisitor &visitor) override;
    Watt power() override;
    Currency netPrice() override;
    Currency discountPrice() override;

private:
    std::vector<Equipment *> _child;
};

// visitor
class EquipmentVisitor {
public:
    virtual void forFloppyDisk(FloppyDisk *) = 0;
    virtual void forCard(Card *) = 0;
    virtual void forBus(Bus *) = 0;
    virtual void forComposite(Composite *) = 0;
};

class VisitPower : public EquipmentVisitor {
public:
    void forFloppyDisk(FloppyDisk *) override;
    void forCard(Card *) override;
    void forBus(Bus *) override;
    void forComposite(Composite *) override;

    Watt getPower() { return _power; }

private:
    Watt _power{0};
};

class VisitNetPrice : public EquipmentVisitor {
public:
    void forFloppyDisk(FloppyDisk *) override;
    void forCard(Card *) override;
    void forBus(Bus *) override;
    void forComposite(Composite *) override;

    Currency getNetPrice() { return _price; }

private:
    Currency _price{0};
};

class VisitDiscountPrice : public EquipmentVisitor {
public:
    void forFloppyDisk(FloppyDisk *) override;
    void forCard(Card *) override;
    void forBus(Bus *) override;
    void forComposite(Composite *) override;

    Currency getDiscountPrice() { return _price; }

private:
    Currency _price{0};
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_VISITOR_H
