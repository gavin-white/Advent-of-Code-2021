#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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



