#pragma once

#include "heapproxy.h"

#include <ostream>


class LogHeapProxy : public HeapProxy {

std::ostream& out;

public:

LogHeapProxy(Heap& heap)
	: HeapProxy()
{}

byte_t read(size_t idx) override {
	out << &(this->memory)  << " read: " << idx << "-th byte" << std::endl;
	return this->memory.read(idx);
}

void write(size_t idx, byte_t value) override {
	out << &(this->memory) << " write: " << idx << "-th byte" << std::endl;
	return this->memory.write(idx);
}


}
