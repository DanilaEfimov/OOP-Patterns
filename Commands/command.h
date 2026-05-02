// file command.h
// interface of a VM command

#pragma once

#include "memstack.h"
#include "memstack.h"

class Command {

public:

// @param stack : Stack& - memory stack
virtual void excecute(Stack& stack) = 0;

}

