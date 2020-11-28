// Copyright 2020 Eric Kumar
#include <iostream>
#include <string>
#include <cstdint>
#include <exception>
#include <stdexcept>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <SFML/Audio.hpp>
#include "StringSound.h"
#include "CircularBuffer.h"
#include <boost/exception/all.hpp>
#include <boost/test/included/unit_test.hpp>
// StringSound Tests
BOOST_AUTO_TEST_CASE(good_constructors_and_sample_StringSound) {
  StringSound test(220);
  std::vector<sf::Int16> test1;
  test1.reserve(5);
  for (int i = 0; i < 5; i++) {
    test1.push_back(5);
  }
  StringSound test2(test1);
  BOOST_REQUIRE(test2.sample() == 5);
}
BOOST_AUTO_TEST_CASE(bad_constructors_StringSound) {
  BOOST_REQUIRE_THROW(StringSound test(0), std::invalid_argument);
  std::vector<sf::Int16> test1;
  BOOST_REQUIRE_THROW(StringSound test(test1), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(pluck_StringSound) {
  StringSound test(220);
  BOOST_REQUIRE_NO_THROW(test.pluck());
  BOOST_REQUIRE_NO_THROW(test.sample());
}
BOOST_AUTO_TEST_CASE(tic_and_time_StringSound) {
  StringSound test(220);
  test.pluck();
  test.tic();
  BOOST_REQUIRE_NO_THROW(test.sample());
  BOOST_REQUIRE(test.time() == 1);
}
// CircularBuffer Tests
BOOST_AUTO_TEST_CASE(good_constructor_CircularBuffer) {
  BOOST_REQUIRE_NO_THROW(CircularBuffer test(5));
}
BOOST_AUTO_TEST_CASE(bad_constructor_CircularBuffer) {
  BOOST_REQUIRE_THROW(CircularBuffer test(0), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(size_CircularBuffer) {
  CircularBuffer test(5);
  BOOST_REQUIRE(test.size() == 0);
}
BOOST_AUTO_TEST_CASE(empty_CircularBuffer) {
  CircularBuffer test(5);
  BOOST_REQUIRE(test.isEmpty());
}
BOOST_AUTO_TEST_CASE(enqueue_CircularBuffer) {
  CircularBuffer test(5);
  int16_t test_num = 4;
  test.enqueue(test_num);
  BOOST_REQUIRE(test.size() == 1);
}
BOOST_AUTO_TEST_CASE(bad_enqueue_CircularBuffer) {
  CircularBuffer test(1);
  int16_t test_num = 1;
  test.enqueue(test_num);
  BOOST_REQUIRE_THROW(test.enqueue(test_num), std::runtime_error);
}
BOOST_AUTO_TEST_CASE(dequeue_CircularBuffer) {
  CircularBuffer test(5);
  int16_t test_num = 1;
  test.enqueue(test_num);
  test_num = test.dequeue();
  BOOST_REQUIRE(test.size() == 0);
}
BOOST_AUTO_TEST_CASE(bad_dequeue_CircularBuffer) {
  CircularBuffer test(1);
  BOOST_REQUIRE_THROW(test.dequeue(), std::runtime_error);
}
BOOST_AUTO_TEST_CASE(peek_CircularBuffer) {
  CircularBuffer test(5);
  int16_t test_num = 1;
  test.enqueue(test_num);
  BOOST_REQUIRE(test.peek() == 1);
}
BOOST_AUTO_TEST_CASE(bad_peek_CircularBuffer) {
  CircularBuffer test(1);
  BOOST_REQUIRE_THROW(test.peek(), std::runtime_error);
}
