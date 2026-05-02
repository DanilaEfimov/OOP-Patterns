// interface of a VM command

#pragma once

#include "memstack.h"
#include "memstack.h"

class Command {

public:

virtual void excecute(Stack& stack) = 0;

}

