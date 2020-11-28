// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <exception>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <SFML/System.hpp>
#include "MModel.h"
#include <boost/exception/all.hpp>
#include <boost/test/included/unit_test.hpp>
// ED Tests
BOOST_AUTO_TEST_CASE(good_constructor) {
  BOOST_REQUIRE_NO_THROW(MModel test("abc", 3));
}
BOOST_AUTO_TEST_CASE(bad_constructor) {
  BOOST_REQUIRE_THROW(MModel test("abc", 4), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(k) {
  MModel test("abc", 3);
  BOOST_REQUIRE(test.kOrder() == 3);
}
BOOST_AUTO_TEST_CASE(freq) {
  MModel test("gagggagaggcgagaaa", 3);
  BOOST_REQUIRE_THROW(test.freq("a"), std::runtime_error);
  BOOST_REQUIRE_THROW(test.freq("a", 'h'), std::runtime_error);
  BOOST_REQUIRE(test.freq("gag") == 4);
  BOOST_REQUIRE(test.freq("zed") == 0);
  BOOST_REQUIRE(test.freq("gag", 'g') == 2);
  BOOST_REQUIRE(test.freq("gag", 'n') == 0);
  MModel test2("gagggagaggcgagaaa", 1);
  BOOST_REQUIRE(test2.freq("c") == 1);
  BOOST_REQUIRE(test2.freq("g", 'a') == 5);
}
BOOST_AUTO_TEST_CASE(lambda_expression_extra_credit) {
  MModel test3("gagggagaggcgagaaa", 0);
  BOOST_REQUIRE(test3.freq("", 'a') == 7);
}
BOOST_AUTO_TEST_CASE(kRand_and_generate) {
  MModel test("gagggagaggcgagaaa", 2);
  BOOST_REQUIRE_THROW(test.kRand("a"), std::runtime_error);
  BOOST_REQUIRE_THROW(test.kRand("ze"), std::runtime_error);
  BOOST_REQUIRE_THROW(test.generate("a", 20), std::runtime_error);
  BOOST_REQUIRE_NO_THROW(test.kRand("ga"));
  BOOST_REQUIRE_NO_THROW(test.generate("ga", 20));
}
BOOST_AUTO_TEST_CASE(output) {
  MModel test("gagggagaggcgagaaa", 2);
  std::cout << test << std::endl;
}
