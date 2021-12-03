#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

int main(int argc, char ** args) {
  if (argc != 2) {
    std::cout << "Program takes exactly 1 argument, the name of the file "
      << "to read input from. You gave " << argc - 1 << " arguments." << std::endl;
    return -1;
  }
  std::ifstream file (args[1]);
  if (file.is_open()) {
    solution(file);
    file.close();
  } else {
    std::cout << "Unable to open file!" << std::endl; 
  }
}
