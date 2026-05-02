// file memstack.h
// VM stack model

#pragma once

#include <cstddef>
#include <stack>
#include <stdexcept>

using value_t = uint64_t;

class Stack {

std::stack<value_t> mem;
size_t maxSize;

public:

// @param max_size : size_t - max stack size
explicit Stack(size_t max_size) 
	: maxSize(max_size), mem()
{}

// @param val : value_t - value to push
// @throws std::runtime_error
void push(value_t val) {
	if(this->size() >= this->maxSize)
		throw std::runtime_error("Stack::push::stack overflow");	

	this->mem.push(val);
}

// @returns value_t : top value if it's exists
// @throws std::runtime_error
value_t pop() {
	if(this->empty())
		throw std::runtime_error("Stack::pop::stack underflow");

	return this->mem.pop();
}

// @returns bool : true if stack is empty, false otherwise
bool empty() const noexcept {
	return this->mem.empty();
}

// @returns size_t : different between max and actual size
size_t remains() const noexcept {
	return this->maxSize - this->size();
}

// @returns size_t : actual size of a stack
size_t size() const noexcept {
	return this->mem.size();
}

}
