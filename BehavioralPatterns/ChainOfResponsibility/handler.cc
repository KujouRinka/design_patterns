#include "handler.h"

void Handler::handleRequest() {
    if (_successor)
        _successor->handleRequest();
}

void Handler::setHandler(Handler *h) {
    _successor = h;
}

Handler::Handler(Handler *h) : _successor(h) {}

Background::Background() : Handler(nullptr) {}

void Background::handleRequest() {
    // do nothing
}

ConcreteHandler::ConcreteHandler(Handler *h) : Handler(h) {}

void ConcreteHandler::handleRequest() {
    if (true /* some case */) {
        concreteHandle();
    } else {
        Handler::handleRequest();
    }
}

void ConcreteHandler::concreteHandle() {
    // do something such as show log, help information...
}

ConcreteHandler2::ConcreteHandler2(Handler *h) : Handler(h) {}

void ConcreteHandler2::handleRequest() {
    if (true /* some case */) {
        concreteHandle();
    } else {
        Handler::handleRequest();
    }
}

void ConcreteHandler2::concreteHandle() {
    // do something
}
