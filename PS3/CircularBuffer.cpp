// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include <exception>
#include <stdexcept>
#include "CircularBuffer.h"
CircularBuffer::CircularBuffer(int capacity) {
  if (capacity < 1) {
    throw std::invalid_argument("Invalid capacity must be at least 1");
  }
  _capacity = capacity;
  _size = 0;
  data.reserve(_capacity);
}
int CircularBuffer::size() {
  return _size;
}
bool CircularBuffer::isEmpty() {
  return(_size == 0);
}
bool CircularBuffer::isFull() {
  return(_size == _capacity);
}
void CircularBuffer::enqueue(int16_t x) {
  if (isFull()) {
    throw std::runtime_error("Buffer full");
  }
  data.push_back(x);
  _size++;
}
int16_t CircularBuffer::dequeue() {
  if (isEmpty()) {
    throw std::runtime_error("Buffer Empty");
  }
  int16_t front = data[0];
  _size--;
  data.erase(data.begin());
  return front;
}
int16_t CircularBuffer::peek() {
  if (isEmpty()) {
  throw std::runtime_error("Buffer Empty No data");
  }
  return data[0];
}
