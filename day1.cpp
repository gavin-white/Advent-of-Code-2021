#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "driver.h"

void solution(std::ifstream & input) {
  std::string line;
  int last = INT32_MAX;
  int current;
  int count = 0;

  while (getline(input, line)) {
    std::stringstream s(line); s >> current;
    if (current > last) 
      ++count;
    last = current;
  }

  std::cout << count << std::endl;
}
