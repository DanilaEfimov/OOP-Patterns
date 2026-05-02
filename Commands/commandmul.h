// file commandmul.h
// multiplication of a two values

#pragma once

#include "command.h"

class CommandMul : public Command {

public:

// aka Command::excecute
void excecute(Stack& stack) override {
	auto right = stack.pop();
	auto left = stack.pop();

	stack.push(left * right);
}

}

