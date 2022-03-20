#ifndef DATA_STRUCTURES_AND_ALGORITHM_COMPOSITE_H
#define DATA_STRUCTURES_AND_ALGORITHM_COMPOSITE_H

#include <unordered_set>

class Component {
public:
    Component(Component *parent = nullptr);

    virtual void operation() = 0;

    virtual bool add(Component *child);
    virtual bool remove(Component *child);

    virtual Component *getChild(int which);
    virtual Component *getParent();
    virtual Component *getComposite();

protected:
    Component *parent_;
};

class Composite : public Component {
public:
    Composite(Component *parent = nullptr);

    void operation() override;

    bool add(Component *child) override;
    bool remove(Component *child) override;
    Component *getChild(int which) override;
    Component *getComposite() override;

private:
    // could be replaced by other container
    std::unordered_set<Component *> _child;
};

class Leaf1 : public Component {
public:
    Leaf1(Component *parent = nullptr);

    void operation() override;
};

class Leaf2 : public Component {
public:
    Leaf2(Component *parent = nullptr);

    void operation() override;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_COMPOSITE_H
