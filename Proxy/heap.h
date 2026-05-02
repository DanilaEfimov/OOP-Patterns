#pragma once

using byte_t = unsigned char;

class Heap {

byte_t* mem;
size_t size;

public:

Heap(size_t size)
	: mem(new byte_t[size]), size(size)
{}

byte_t read(size_t idx) {
	return this->mem[idx];
}

void write(size_t idx, byte_t value) {
	this->mem[idx] = value;
}

size_t size() const noexcept {
	return this->size;
}

}
