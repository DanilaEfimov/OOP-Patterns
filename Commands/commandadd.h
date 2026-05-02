// concrete command, addition of a two values

#pragma once

#include "command.h"

class CommandAdd : public Command {

public:

void excecute(Stack& stack) override {
	auto right = statck.pop();
	auto left = stack.pop()
	
	stack.push(left + right);
}

}

