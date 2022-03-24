#include "Observer.h"

#include "Subject.h"

ConcreteObserver::ConcreteObserver(ConcreteSubject *co) : _cs(co) {
    _cs->attach(this);
}

ConcreteObserver::~ConcreteObserver() noexcept {
    _cs->detach(this);
}

void ConcreteObserver::update(Subject *changed_subject) {
    if (changed_subject != _cs)
        return;
    _observer_stat = _cs->getStat();
}

void ConcreteObserver::removeRef(Subject *detached_subject) {
    if (detached_subject != _cs)
        return;
    _cs = nullptr;
}

int ConcreteObserver::getStat() {
    return _observer_stat;
}
