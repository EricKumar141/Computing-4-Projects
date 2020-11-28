// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <map>
#include <memory>
#include <string>
#include <algorithm>
#include <SFML/System.hpp>
#include "MModel.h"

int main(int argc, char* argv[]) {
  int k = atof(argv[1]);
  int L = atof(argv[2]);
  std::string input; // NOLINT
  std::string to_add; // NOLINT
  std::getline(std::cin, to_add);
  input += to_add;
  MModel test(input, k);
  std::cout << test.generate(input.substr(0, k), L) << std::endl;
  return 0;
}

