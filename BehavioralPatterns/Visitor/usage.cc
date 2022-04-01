#include <iostream>

#include "Visitor.h"

void example() {
    Equipment *composite = new Composite({new FloppyDisk, new FloppyDisk, new Card, new Bus});
    VisitPower power;
    VisitNetPrice netPrice;
    VisitDiscountPrice discountPrice;

    composite->accept(power);
    composite->accept(netPrice);
    composite->accept(discountPrice);

    std::cout << "Power: " << power.getPower() << std::endl
              << "Net Price: " << netPrice.getNetPrice() << std::endl
              << "Discount Price: " << discountPrice.getDiscountPrice() << std::endl;
}
