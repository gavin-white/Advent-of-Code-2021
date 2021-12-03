#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "driver.h"

void solution(std::ifstream & input) {
  int depth = 0;
  int position = 0;
  std::string command;
  std::string line;
  int magnitude;

  while(getline(input, line)) {
    std::stringstream s(line);
    s >> command;
    s >> magnitude;
    if (command == "forward") {
      position += magnitude;
    } else if (command == "up") {
      depth -= magnitude;
    } else if (command == "down") {
      depth += magnitude;
    }
  }

  std::cout << depth * position << std::endl; 
}
