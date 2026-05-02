#pragma once

#include "decorator.h"
#include "Command/stack.h"

class OverflowCheck : public Decorator
{

size_t critical;

public:
OverflowCheck(Command* command, size_t critical)
	: Decorator(command), critical(critical)
{}

void call(Stack& stack) override {
	if(stack.remains() > this->critical)
		this->cmd->excecute(stack);
}

}
