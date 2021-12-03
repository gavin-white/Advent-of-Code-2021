#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "driver.h"

void solution(std::ifstream & input) {
  int position = 0;
  int aim = 0;
  int depth = 0;
  std::string command;
  std::string line;
  int magnitude;

  while(getline(input, line)) {
    std::stringstream s(line);
    s >> command;
    s >> magnitude;
    if (command == "forward") {
      position += magnitude;
      depth += magnitude * aim;
    } else if (command == "up") {
      aim -= magnitude;
    } else if (command == "down") {
      aim += magnitude;
    }
  }

  std::cout << depth * position << std::endl; 
}
