#pragma once

#include <cstddef>
#include <stack>
#include <stdexcept>

using value_t = uint64_t;

class Stack {

std::stack<value_t> mem;
size_t maxSize;

public:

// prime constructor
explicit Stack(size_t max_size) 
	: maxSize(max_size), mem()
{}

// push value to the top of a stask
void push(value_t val) {
	if(this->size() >= this->maxSize)
		throw std::runtime_error("Stack::push::stack overflow");	

	this->mem.push(val);
}

// erase single value from the top of a stack
value_t pop() {
	if(this->empty())
		throw std::runtime_error("Stack::pop::stack underflow");

	return this->mem.pop();
}

// check of an emptyness
bool empty() const noexcept {
	return this->mem.empty();
}

// different between max size and actual
size_t remains() const noexcept {
	return this->maxSize - this->size();
}

// actual size of a stack
size_t size() const noexcept {
	return this->mem.size();
}

}
