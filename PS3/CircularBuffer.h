// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#ifndef CIRCULAR_BUFFER_H_ // NOLINT
#define CIRCULAR_BUFFER_H_ // NOLINT

class CircularBuffer{
 public:
CircularBuffer(int capacity);
int size();
bool isEmpty();
bool isFull();
void enqueue(int16_t x);
int16_t dequeue();
int16_t peek();
 private:
int _size;
int _capacity;
std::vector<int16_t> data;
};
#endif // NOLINT
