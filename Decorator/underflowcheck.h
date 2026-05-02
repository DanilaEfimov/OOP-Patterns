#pragma once

#include "decorator.h"

class UnderflowCheck : public Decorator
{

size_t critical;

public:

Underflow(Command* command, size_t critical)
	: Decorator(command), critical(critical)
{}

void call(Stack& stack) override {
	if(stack.size() > this->critical)
		this->cmd->excecute(stack);
}

}
