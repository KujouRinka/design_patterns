#include "Composite.h"

Component::Component(Component *parent) : parent_(parent) {}

void Component::operation() {
    // do something
    // std::cout << "hello!!" << std::endl;
}

// defined for child
bool Component::add(Component *child) {
    return false;
}

// defined for child
bool Component::remove(Component *child) {
    return false;
}

// defined for child
Component *Component::getChild(int which) {
    return nullptr;
}

Component *Component::getParent() {
    return parent_;
}

// defined for child
Component *Component::getComposite() {
    return nullptr;
}


Composite::Composite(Component *parent) : Component(parent) {}

void Composite::operation() {
    // do something
    // std::cout << "!!" << std::endl;
    for (Component *c: _child)
        c->operation();
}

bool Composite::add(Component *child) {
    return _child.insert(child).second;
}

bool Composite::remove(Component *child) {
    // delete child;
    return _child.erase(child) == 1;
}

Component *Composite::getChild(int which) {
    // return a child according to parameter
    return nullptr;
}

Component *Composite::getComposite() {
    return this;
}

Leaf1::Leaf1(Component *parent) : Component(parent) {}

void Leaf1::operation() {
    // do something
}

Leaf2::Leaf2(Component *parent) : Component(parent) {
    // do something
}

void Leaf2::operation() {
    // do something
}
