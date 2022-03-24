#include <iostream>
#include "Observer/Observer.h"
#include "Observer/Subject.h"

using namespace std;

int main() {
    ConcreteSubject *s = new ConcreteSubject;
    s->setStat(233);

    ConcreteObserver *ob1 = new ConcreteObserver(s);
    ConcreteObserver *ob2 = new ConcreteObserver(s);
    cout << ob1->getStat() << " " << ob2->getStat() << endl;
    s->setStat(42);
    cout << ob1->getStat() << " " << ob2->getStat() << endl;

    ConcreteObserver *ob3 = new ConcreteObserver(s);
    cout << ob1->getStat() << " " << ob2->getStat() << " " << ob3->getStat() << endl;
    s->setStat(114514);
    cout << ob1->getStat() << " " << ob2->getStat() << " " << ob3->getStat() << endl;
    delete ob3;
    cout << ob1->getStat() << " " << ob2->getStat() << endl;
    s->setStat(1);
    cout << ob1->getStat() << " " << ob2->getStat() << endl;

    delete s;
    cout << "hello" << endl;

    return 0;
}