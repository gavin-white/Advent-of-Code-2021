#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "driver.h"

void solution(std::ifstream & input) {
  std::string line;
  std::vector<long> timers = std::vector<long>(9, 0);
  getline(input, line);
  for (char c : line) {
    if (c != ',') {
      timers[c - '0']++;
    }
  }

  for (int i = 0; i < 256; i++) {
    // 6 + [0] , 8 + [0], 0 - [0], 

    long num_zeroes = timers[0];
    for (int i = 0; i < timers.size() - 1; i++) {
      timers[i] += timers[i + 1];
      timers[i + 1] = 0;
    }
    timers[8] = num_zeroes;
    timers[6] += num_zeroes;
    timers[0] -= num_zeroes;
  }

  long long total_fish = 0;
  for (int i = 0; i < timers.size(); i++) {
    total_fish += timers[i];
  }

  std::cout << total_fish << std::endl;
}
