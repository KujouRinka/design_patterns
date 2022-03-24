#ifndef DATA_STRUCTURES_AND_ALGORITHM_OBSERVER_H
#define DATA_STRUCTURES_AND_ALGORITHM_OBSERVER_H

class Subject;
class ConcreteSubject;

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(Subject *changed_subject) = 0;
    virtual void removeRef(Subject *detached_subject) = 0;

protected:
    Observer() = default;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(ConcreteSubject *co);
    ~ConcreteObserver() override;

    void update(Subject *changed_subject) override;
    void removeRef(Subject *detached_subject) override;

    int getStat();

private:
    ConcreteSubject *_cs;

    int _observer_stat;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_OBSERVER_H
