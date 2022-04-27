#include "invoker.h"
#include "receiver.h"
#include "command.h"

void example() {
    MacroCommand *macro = new MacroCommand;
    Invoker *invoker = new Invoker(macro);

    Command *c1 = new ConcreteCommand(new Receiver);
    Command *c2 = new ConcreteCommand(new Receiver);
    Command *simple_command = new SimpleCommand<Receiver>(new Receiver, &Receiver::action2);
    macro->add(c1);
    macro->add(c2);
    macro->add(simple_command);

    invoker->invoke();
}
