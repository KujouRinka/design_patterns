#include "command.h"
#include "receiver.h"

void MacroCommand::execute() {
    for (Command *cmd: _cmds)
        cmd->execute();
}

void MacroCommand::add(Command *cmd) {
    _cmds.insert(cmd);
}

void MacroCommand::remove(Command *cmd) {
    _cmds.erase(cmd);
}

ConcreteCommand::ConcreteCommand(Receiver *r) : _r(r) {}

void ConcreteCommand::execute() {
    _r->action();
}
