#include "Decorator.h"

void ConcreteComponent::operation1() {
    // do something
}

void ConcreteComponent::operation2() {
    // do something
}

Decorator::Decorator(Component *component) : _component(component) {}

void Decorator::operation1() {
    _component->operation1();
}

void Decorator::operation2() {
    _component->operation2();
}

ConcreteDecorator::ConcreteDecorator(Component *component) : Decorator(component) {
    // make some decorations
}

void ConcreteDecorator::operation1() {
    // make some decorations
    Decorator::operation1();
    // make some decorations
}

void ConcreteDecorator::operation2() {
    // make some decorations
    Decorator::operation2();
    // make some decorations
}
