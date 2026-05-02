#pragma once

#include "Command/command.h"
#include "Command/stack.h"

class Decorator {

Command* cmd;

public:

Decorator(Command* cmd)
	: cmd(command)
{}

virtual void call(Stack& stack) = 0;

}

