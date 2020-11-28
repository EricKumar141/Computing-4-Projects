// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include <exception>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <SFML/System.hpp>
#include "ED.h"

ED::ED(std::string a, std::string b) : first(a), second(b) {
  if (first.size() <= 0 || second.size() <= 0) {
    throw std::invalid_argument("at least 1 of the inputted strings is empty");
  }
  int i;
  int j;
  int _size;
  matrix.resize(first.size()+1);
  _size = matrix.size();
  for (i = 0; i < _size; i++) {
    matrix.at(i).resize(second.size()+1);
  }
  m = first.size();
  n = second.size();
  for (i = 0; i <= m; i++) {
    matrix.at(i).at(n) = 2*(m-i);
  }
  for (j = 0; j <= n; j++) {
    matrix.at(m).at(j) = 2*(n-j);
  }
}
int ED::penalty(char a, char b) {
  if (a == b) {
    return 0;
  } else {
    return 1;
  }
}
int ED::min(int a, int b, int c) {
  if (a <= b && a <= c) {
    return a;
  } else if (b <= a && b <= c) {
    return b;
    } else {
      return c;
    }
}
int ED::OptDistance() {  // done dynamically with Needleman-Wunsch method
  int i;
  int j;
  for (i = m-1; i >= 0; i--) {
    for (j = n-1; j >= 0; j--) {
      matrix.at(i).at(j) =  min(matrix.at(i+1).at(j+1) + penalty(first.at(i), second.at(j)), matrix.at(i+1).at(j) + 2, matrix.at(i).at(j+1) + 2); // NOLINT
      }
    }
  return matrix.at(0).at(0);
}
std::string ED::Alignment() {
  int i = 0;
  int j = 0;
  std::string output;
  while (i < m && j < n) {
    if (matrix.at(i).at(j) == matrix.at(i+1).at(j+1) + penalty(first.at(i), second.at(j))) {  // NOLINT
      output += first.at(i);
      output += " ";
      output += second.at(j);
      output += " ";
      if (penalty(first.at(i), second.at(j)) == 1) {
        output += "1";
      } else {
        output += "0";
      }
      output += "\n";
      i++;
      j++;
    } else if (matrix.at(i).at(j) == matrix.at(i+1).at(j) + 2) {  // case 2
      output += first.at(i);
      output += " ";
      output += "-";
      output += " ";
      output += "2";
      output += "\n";
      i++;
    } else {  // case 3
      output += "-";
      output += " ";
      output += second.at(j);
      output += " ";
      output += "2";
      output += "\n";
      j++;
    }
  }
  if (j < n) {
    while (j < n) {
      output += "-";
      output += " ";
      output += second.at(j);
      output += " ";
      output += "2";
      output += "\n";
      j++;
    }
  } else if (i < m) {
      while (i < m) {
      output += first.at(i);
      output += " ";
      output += "-";
      output += " ";
      output += "2";
      output += "\n";
      i++;
      }
    }
  return output;
}
