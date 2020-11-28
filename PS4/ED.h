// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <SFML/System.hpp>
#ifndef ED_H_ // NOLINT
#define ED_H_ // NOLINT

class ED{
 public:
ED(std::string a, std::string b);
int penalty(char a, char b);
int min(int a, int b, int c);
int OptDistance();
std::string Alignment();
 private:
std::string first; // NOLINT
std::string second; // NOLINT
std::vector<std::vector<int>> matrix;
int m;
int n;
};
#endif // NOLINT
