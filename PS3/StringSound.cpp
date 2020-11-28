// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <stdexcept>
#include <SFML/Audio.hpp>
#include "StringSound.h"

StringSound::StringSound(double frequency) : sounds(new CircularBuffer(ceil(44100/frequency))){ //NOLINT
  if (ceil(44100/frequency) < 1 || sounds == nullptr) {
    delete sounds;
    throw std::invalid_argument("invalid frequency must be greater than 1");
  }
  tic_count = 0;
}
StringSound::StringSound(std::vector<sf::Int16> init) : sounds(new CircularBuffer(init.size())) { //NOLINT
  if (init.size() < 1 || sounds == nullptr) {
    delete sounds;
    throw std::invalid_argument("invalid vector size must be at least 1");
  }
  int temp_size = init.size();
  for (int i = 0; i < temp_size; i++) {
    this->sounds->enqueue(init[i]);
  }
  tic_count = 0;
}
void StringSound::pluck() {
  while (!this->sounds->isEmpty()) {
    int16_t remove = this->sounds->dequeue();
    remove++;
  }
  std::srand(std::time(0)); //NOLINT
  while (!this->sounds->isFull()) {
    int16_t seed = (int16_t)std::rand()%+32767; //NOLINT
    if (rand() % 2 == 1){ //NOLINT
      seed = seed*-1;
    }
  this->sounds->enqueue(seed);
  }
}
void StringSound::tic() {
  int16_t front = this->sounds->dequeue();
  int16_t second = this->sounds->peek();
  int16_t to_add = .966*(.5*front*(second));
  this->sounds->enqueue(to_add);
  tic_count++;
}
sf::Int16 StringSound::sample() {
  return this->sounds->peek();
}
int StringSound::time() {
  return tic_count;
}
