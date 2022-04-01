#include <cstring>

#include "Visitor.h"

Equipment::Equipment(const char *name) {
    _name = strdup(name);
}

void FloppyDisk::accept(EquipmentVisitor &visitor) {
    visitor.forFloppyDisk(this);
}

void Card::accept(EquipmentVisitor &visitor) {
    visitor.forCard(this);
}

void Bus::accept(EquipmentVisitor &visitor) {
    visitor.forBus(this);
}

void Composite::accept(EquipmentVisitor &visitor) {
    visitor.forComposite(this);
}

Watt Composite::power() {
    Watt p = 0;
    for (auto i: _child)
        p += i->power();
    return p;
}

Currency Composite::netPrice() {
    Currency c = 0;
    for (auto i: _child)
        c += i->netPrice();
    return c;
}

Currency Composite::discountPrice() {
    Currency c = 0;
    for (auto i: _child)
        c += i->discountPrice();
    return c;
}

void VisitPower::forFloppyDisk(FloppyDisk *floppyDisk) {
    _power += floppyDisk->power();
}

void VisitPower::forCard(Card *card) {
    _power += card->power();
}

void VisitPower::forBus(Bus *bus) {
    _power += bus->power();
}

void VisitPower::forComposite(Composite *composite) {
    _power += composite->power();
}

void VisitNetPrice::forFloppyDisk(FloppyDisk *floppyDisk) {
    _price += floppyDisk->netPrice();
}

void VisitNetPrice::forCard(Card *card) {
    _price += card->netPrice();
}

void VisitNetPrice::forBus(Bus *bus) {
    _price += bus->netPrice();
}

void VisitNetPrice::forComposite(Composite *composite) {
    _price += composite->netPrice();
}

void VisitDiscountPrice::forFloppyDisk(FloppyDisk *floppyDisk) {
    _price += floppyDisk->discountPrice();
}

void VisitDiscountPrice::forCard(Card *card) {
    _price += card->discountPrice();
}

void VisitDiscountPrice::forBus(Bus *bus) {
    _price += bus->discountPrice();
}

void VisitDiscountPrice::forComposite(Composite *composite) {
    _price += composite->discountPrice();
}
