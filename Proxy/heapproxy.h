#pragma once

#include "heap.h"


class HeapProxy {

Heap& memory;

public:

HeapProxy(Heap& heap)
	: memory(heap)
{}

virtual byte_t read(size_t idx) = 0;

virtual void write(size_t idx, byte_t value) = 0;

}
