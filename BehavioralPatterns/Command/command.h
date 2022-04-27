#ifndef COMMAND_H
#define COMMAND_H

#include <unordered_set>
#include "receiver.h"

class Command {
public:
    virtual void execute() = 0;
};

class MacroCommand : public Command {
public:
    MacroCommand() = default;
    void execute() override;

    void add(Command *cmd);
    void remove(Command *cmd);

private:
    std::unordered_set<Command *> _cmds;
};

class ConcreteCommand : public Command {
public:
    ConcreteCommand(Receiver *r);
    void execute() override;

private:
    Receiver *_r;
};

template<typename Receiver_T>
class SimpleCommand : public Command {
public:
    using ActionFunc = void (Receiver_T::*)();
    SimpleCommand(Receiver_T *r, ActionFunc f)
        : _action(f), _r(r) {}

    void execute() override {
        (_r->*_action)();
    }

private:
    ActionFunc _action;
    Receiver_T *_r;
};

#endif
