#pragma once

#include "heapproxy.h"


class ReadOnlyHeapProxy : HeapProxy {

public:

ReadOnlyHeapProxy(Heap& heap)
	: HeapProxy(heap)
{}

byte_t read(size_t idx) override {
	return this->memory.read(idx);
}

void write(size_t idx, byte_t value) override {
	throw std::logic_error("ReadOnlyHeapProxy::write: heap can not be writen");
}

}
