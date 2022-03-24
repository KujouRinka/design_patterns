#include "Subject.h"

#include "Observer.h"

Subject::~Subject() {
    for (auto observer: _observers)
        observer->removeRef(this);
}

void Subject::notify() {
    for (auto observer: _observers)
        observer->update(this);
}

void Subject::attach(Observer *observer) {
    _observers.insert(observer);
    observer->update(this);
}

void Subject::detach(Observer *observer) {
    observer->removeRef(this);
    _observers.erase(observer);
}

int ConcreteSubject::getStat() {
    return _subject_stat;
}

void ConcreteSubject::setStat(int value) {
    _subject_stat = value;
    notify();
}

