#pragma once

#include "heapproxy.h"


class SafeHeapProxy : public HeapProxy {

bool outOfBound = false;

public:

SafeHeapProxy(Heap& heap)
	: HeapProxy(heap)
{}

byte_t read(size_t idx) override {
	if(idx < this->memory.size()){
		this->outOfBound = false;
		return this->memory.read(idx);
	}
	this->outOfBound = true;
}

void write(size_t idx, byte_t value) override {
	if(idx < this->memory.size()){
		this->outOfBound = false;
		return this->memory.read(idx);
	}
	this->outOfBound = true;
}

}
