// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include <exception>
#include <stdexcept>
#include <string>
#include <SFML/System.hpp>
#include "ED.h"

int main() {
  sf::Clock clock;
  sf::Time t;
  std::string a;
  std::string b;
  std::cin >> a;
  std::cin >> b;
  ED to_compare(a, b);
  std::cout << "Edit Distance = " << to_compare.OptDistance() << std::endl;
  std::cout << to_compare.Alignment() << std::endl;
  t = clock.getElapsedTime();
  std::cout << "Execution time is " << t.asSeconds() << " seconds"<< std::endl;
  return 0;
}
