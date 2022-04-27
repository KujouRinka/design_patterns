#include "handler.h"

void example() {
    Handler *bg = new Background;
    Handler *c1 = new ConcreteHandler(bg);
    Handler *c2 = new ConcreteHandler2(c1);

    // request will be passed as:
    // c2  --->  c1 --->  bg
    c2->handleRequest();
}
