#ifndef DATA_STRUCTURES_AND_ALGORITHM_DECORATOR_H
#define DATA_STRUCTURES_AND_ALGORITHM_DECORATOR_H

class Component {
public:
    Component() = default;

    virtual void operation1() = 0;
    virtual void operation2() = 0;
};

class ConcreteComponent : public Component {
public:
    ConcreteComponent() = default;

    void operation1() override;
    void operation2() override;
};

class Decorator : public Component {
public:
    Decorator(Component *component);

    void operation1() override;
    void operation2() override;

private:
    Component *_component;
};

class ConcreteDecorator : public Decorator {
public:
    ConcreteDecorator(Component *component);

    void operation1() override;
    void operation2() override;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_DECORATOR_H
