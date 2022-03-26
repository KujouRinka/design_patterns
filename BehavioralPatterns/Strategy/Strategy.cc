#include "Strategy.h"

void Context::doSomething() {
    // do something
    _strategy->AlgorithmInterface(this);
    // do something
}

void Context::changeMethod(Strategy *strategy) {
    _strategy = strategy;
}

void Strategy::AlgorithmInterface(Context *ctx) {
    // implement algorithm for default calling
}

void ConcreteStrategy1::AlgorithmInterface(Context *ctx) {
    // implement algorithm for method 1
}

void ConcreteStrategy2::AlgorithmInterface(Context *ctx) {
    // implement algorithm for method 2
}
