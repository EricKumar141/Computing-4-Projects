// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <memory>
#include <SFML/Audio.hpp>
#include "CircularBuffer.h"
#ifndef STRING_SOUND_H_ // NOLINT
#define STRING_SOUND_H_ // NOLINT

class StringSound{
 public:
StringSound(double frequency);
StringSound(std::vector<sf::Int16> init);
void pluck();
void tic();
sf::Int16 sample();
int time();
 private:
CircularBuffer* sounds;
int tic_count;
};

#endif // NOLINT
