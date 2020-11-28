// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <algorithm>
#include <SFML/System.hpp>
#ifndef MModel_H_ // NOLINT
#define MModel_H_ // NOLINT

class MModel {
 public:
MModel(std::string text, int k);
int kOrder();
int freq(std::string kgram);
int freq(std::string kgram, char c);
char kRand(std::string kgram);
std::string generate(std::string kgram, int L);
friend std::ostream& operator<< (std::ostream &out, MModel &c);
 private:
std::string my_text; // NOLINT
std::string my_kgram; // NOLINT
std::map<std::string, std::map<char, std::string>> my_map; // NOLINT
int korder;
};
#endif // NOLINT
