// Copyright 2020 Eric Kumar
#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <string>
#include <boost/regex.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;
using boost::posix_time::ptime;
using boost::posix_time::time_duration;
int main(int argc, char* argv[]) {
  std::ifstream kronus(argv[1]);
  std::string input_file = argv[1];
  int line = 0;
  int started = 0;
  date d1;
  date d2;
  ptime t1;
  ptime t2;
  std::ofstream output_file(input_file + ".rpt", std::ofstream::out);
  std::string current_line;
  boost::regex start("[(]log[.]c[.]166[)] server started");
  boost::regex end("oejs[.]AbstractConnector:Started SelectChannelConnector"); // NOLINT
  if (kronus.is_open() && output_file.is_open()) {
    output_file << "Device Boot Report\n"
    << "InTouch log file: " << input_file << "\n\n";
    while (getline(kronus, current_line)) {
      ++line;
      if (boost::regex_search(current_line, start)) {  // startup
        if (started == 1) {  // startup found again before a completion
          output_file << "Startup failed \n\n";
          started = 0;
        }
          output_file << current_line
          << "at line: " << line << "\n";
          started = 1;
          std::string temp_date = current_line.substr(0, 10);  // to make date
          std::string temp_time = current_line.substr(11, 8);  // to make time
          d1 = from_simple_string(temp_date);
          ptime temp(d1, time_duration(stoi(temp_time.substr(0, 2)), stoi(temp_time.substr(3, 2)), stoi(temp_time.substr(6, 2)), 0)); // NOLINT
          t1 = temp;
        } else if (boost::regex_search(current_line, end)) {  // completion
        if (started == 1) {
          std::string temp_date = current_line.substr(0, 10);  // to make date
          std::string temp_time = current_line.substr(11, 8);  // to make time
          d2 = from_simple_string(temp_date);
          ptime temp(d2, time_duration(stoi(temp_time.substr(0, 2)), stoi(temp_time.substr(3, 2)), stoi(temp_time.substr(6, 2)), 0)); // NOLINT
          t2 = temp;
          std::string date_time = current_line.substr(0, 19);
          time_duration td = t2-t1;
          output_file << date_time << ": " << "Startup Success \n"
          << "Elasped Time: " << td.total_milliseconds() << " ms\n\n";
          started = 0;
        }
      }
    }
  }
  if (started == 1) {  // if last startup failed
    output_file << "Startup failed \n\n";
    started = 0;
  }
  kronus.close();
  output_file.close();
  return 0;
}
