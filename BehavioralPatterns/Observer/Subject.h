#ifndef DATA_STRUCTURES_AND_ALGORITHM_SUBJECT_H
#define DATA_STRUCTURES_AND_ALGORITHM_SUBJECT_H

#include <unordered_set>

class Observer;

class Subject {
public:
    virtual ~Subject();

    virtual void notify();
    virtual void attach(Observer *observer);
    virtual void detach(Observer *observer);

protected:
    Subject() = default;

private:
    std::unordered_set<Observer *> _observers;
};

class ConcreteSubject : public Subject {
public:
    ConcreteSubject() = default;

    int getStat();
    void setStat(int value);

private:
    int _subject_stat;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_SUBJECT_H
