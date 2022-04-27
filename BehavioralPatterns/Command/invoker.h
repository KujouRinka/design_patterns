#ifndef INVOKER_H
#define INVOKER_H

#include "command.h"

class Invoker {
public:
    Invoker(Command *cmd) : _cmd(cmd) {}
    void invoke() { _cmd->execute(); }

private:
    Command *_cmd;
};

#endif
