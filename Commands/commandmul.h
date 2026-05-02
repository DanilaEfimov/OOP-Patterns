// concrete command, multiplication of a two values

#pragma once

#include "command.h"

class CommandMul : public Command {

public:

void excecute(Stack& stack) override {
	auto right = stack.pop();
	auto left = stack.pop();

	stack.push(left * right);
}

}

