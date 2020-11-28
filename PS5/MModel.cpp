// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <SFML/System.hpp>
#include "MModel.h"

MModel::MModel(std::string text, int k) {
  int test_size = text.size();
  if (k > test_size) {
  throw std::invalid_argument("k does not equal to length of text");
  }
  korder = k;
  my_text = text;
  int i;
  if (korder == 0) {  // if korder = 0 make alternative map
    my_kgram = "";
    for (i = 0; i < 127; i++) {
      if (freq(my_kgram, i) >= 1) {  // if letter has a frequency add to map
        my_map[my_kgram][i] = std::to_string(freq(my_kgram, i)) + "/" + std::to_string(test_size); // NOLINT
      }
  }
  } else {
  int j;
  int n = korder - 1;
  for (i = 0; i + k - 1 < test_size; i++) {
    my_kgram = my_text.substr(i, k);
    for (j = 0; j < 127; j++) {
      if (freq(my_kgram, j) >= 1) {  // if letter has a frequency add to map
        my_map[my_kgram][j] = std::to_string(freq(my_kgram, j)) + "/" + std::to_string(freq(my_kgram)); // NOLINT
      }
    }
  }
  if (test_size != 1) {
    while (i != 0) {  // loop to check some text from beggining of string
    my_kgram = my_text.substr(i, test_size - i) + my_text.substr(0, korder-n);
      for (j = 0; j < 127; j++) {
        if (freq(my_kgram, j) >= 1) {  // if letter has a frequency add to map
          my_map[my_kgram][j] = std::to_string(freq(my_kgram, j)) + "/" + std::to_string(freq(my_kgram)); // NOLINT
        }
    }
    if (i >= test_size-1) {
      i = 0;
    } else {
      i++;
      n--;
    }
  }
  }
  }
}
int MModel::kOrder() {
  return korder;
}
int MModel::freq(std::string kgram) {
  int test_size = kgram.size();
  if (test_size != korder) {
    throw std::runtime_error("k does not equal to the length of inputted string"); // NOLINT
  }
  int i;
  int j = korder - 1;
  int count = 0;
  int size = my_text.size();
  if (test_size == 1) {
    for (i = 0; i < size; i++) {
      if (my_text.substr(i, 1) == kgram) {
        count++;
      }
    }
  } else {
  for (i = 0; i+korder-1 < size; i++) {
    if (my_text.substr(i, korder) == kgram) {
      count++;
    }
  }
  while (i != 0) {  // loop to check some text from beggining of string
    if (my_text.substr(i, size - i) + my_text.substr(0, korder-j) == kgram) {
      count++;
    }
    if (i >= size-1) {
      i = 0;
    } else {
      i++;
      j--;
    }
  }
  }
  return count;
}
int MModel::freq(std::string kgram, char c) {
  int test_size = kgram.size();
  if (test_size != korder) {
    throw std::runtime_error("k does not equal to the length of inputted string"); // NOLINT
  }
  int i;
  int j = korder - 1;
  int count = 0;
  int size = my_text.size();
  if (test_size == 0) {  // order = 0
    auto sum = [](std::string text, char a) {  // lambda expression
    return std::count(text.begin(), text.end(), a); // NOLINT
    };
    return sum(my_text, c);
  } else {
  for (i = 0; i+korder < size; i++) {
  if (my_text.substr(i, korder+1) == kgram + c) {
        count++;
      }
  }
  while (i != 0) {  // loop to check some text from beggining of string
  if (my_text.substr(i, size - i) + my_text.substr(0, korder-j) == kgram + c) {
  count++;
  }
  if (i >= size-1) {
  i = 0;
  } else {
  i++;
  j--;
  }
  }
  return count;
  }
}
char MModel::kRand(std::string kgram) {
  int test_size = kgram.size();
  if (test_size != korder) {
    throw std::runtime_error("k does not equal to the length of inputted string"); // NOLINT
  }
  int frequency = freq(kgram);
  if (frequency <= 0) {
    throw std::runtime_error("kgram not found"); // NOLINT
  }
  std::vector <char> kgram_char;
  int char_frequency;
  for (int i = 0; i < 127; i++) {
    char_frequency = freq(kgram, static_cast<char>(i));
    if (char_frequency > 0) {
      for (int j = 0; j < char_frequency; j++) {
      kgram_char.push_back(static_cast<char>(i));
      }
    }
  }
  int char_to_return = rand(); // NOLINT
  return kgram_char.at(char_to_return % frequency);
}
std::string MModel::generate(std::string kgram, int L) {
  int test_size = kgram.size();
  if (test_size != korder) {
    throw std::runtime_error("korder does not equal to the length of kgram"); // NOLINT
  }
  std::string generated = kgram; // NOLINT
  std::string added; // NOLINT
  int size = kgram.size();
  for (int i = 0; i < L; i++) {
    added = kRand(kgram);
    generated += added;
    if (size == 1) {
      kgram = added;
    } else {
      kgram = kgram.substr(1, size-1) + static_cast<std::string>(added);
    }
  }
  return generated;
}
std::ostream& operator<< (std::ostream &out, MModel &c) {
  int i;
  out << "Order = ";
  out << c.korder;
  out << std::endl;
  out << "Kgram:      Frequency:            Next Character:      Frequency:";
  out << std::endl;
  for (auto const &ent1 : c.my_map) {
    i = 0;
    std::string temp;
    if (c.korder != 0) {
    out << ent1.first;
    out << "                ";
    temp = ent1.first;
    out << c.freq(temp);
    out << std::endl;
    }
    out << "                                        ";
    for (auto const &ent2 : ent1.second) {
      if (i > 0) {
      out << "                                        ";
      }
      out << ent2.first;
      i++;
      out << "                   ";
      out << ent2.second;
      out << std::endl;
  }
  out << "---------------------------------------------";
  out << "------------------------";
  out << std::endl;
  }
return out;
}
