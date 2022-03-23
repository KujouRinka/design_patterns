#include "Decorator.h"

void handle(Component *component) {
    component->operation1();
    component->operation2();
    // ...
}

void example() {
    // Simple
    Component *component = new ConcreteComponent;
    handle(component);

    // With decoration
    Component *decorator = new ConcreteDecorator(component);
    handle(decorator);

    // ...
}
