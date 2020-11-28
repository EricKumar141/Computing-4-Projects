// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <exception>
#include <stdexcept>
#include <string>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <SFML/System.hpp>
#include "ED.h"
#include <boost/exception/all.hpp>
#include <boost/test/included/unit_test.hpp>
// ED Tests
BOOST_AUTO_TEST_CASE(good_constructor) {
  BOOST_REQUIRE_NO_THROW(ED test("abc", "cba"));
}
BOOST_AUTO_TEST_CASE(bad_constructor) {
  BOOST_REQUIRE_THROW(ED test("abc", ""), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(penalty) {
  ED test("abc", "cba");
  BOOST_REQUIRE(test.penalty('a', 'b') == 1);
  BOOST_REQUIRE(test.penalty('a', 'a') == 0);
}
BOOST_AUTO_TEST_CASE(min) {
  ED test("abc", "cba");
  BOOST_REQUIRE(test.min(6, 4, 3) == 3);
  BOOST_REQUIRE(test.min(2, 1, 4) == 1);
  BOOST_REQUIRE(test.min(3, 2, 3) == 2);
}
BOOST_AUTO_TEST_CASE(edit_distance) {
  ED test("AACAGTTACC", "TAAGGTCA");
  BOOST_REQUIRE(test.OptDistance() == 7);
}
