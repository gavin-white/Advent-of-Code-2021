#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "driver.h"

void solution(std::ifstream & input) {
  std::string line;
  std::vector<int> timers;
  getline(input, line);
  for (char c : line) {
    if (c != ',') {
      timers.push_back(c - '0');
    }
  }

  for (int i = 0; i < 80; i++) {
    int num_timers = timers.size();
    for (int j = 0; j < num_timers; j++) {
      if (timers[j] == 0) {
        timers[j] = 6;
        timers.push_back(8);
      } else {
        timers[j]--;
      }
    }
  }

  std::cout << timers.size() << std::endl;
}
