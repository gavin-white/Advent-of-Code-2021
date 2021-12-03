#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void solution(std::ifstream & input) {
  std::string line;
  int last = INT32_MAX;
  int window1 = 0; int window2 = 0; int window3 = 0;
  int current;
  int count = 0;
  int index = 1;

  while (getline(input, line)) {
    std::stringstream s(line); s >> current;
    window1 += current;
    window2 += current;
    window3 += current;
    if (index % 3 == 0) {
      if (window1 > last)
        ++count;
      last = window1;
      window1 = 0;
    }
    if (index > 3) {
      if ((index + 1) % 3 == 0) {
        if (window2 > last)
          ++count;
        last = window2;
        window2 = 0;
      }
      if ((index + 2) % 3 == 0) {
        if (window3 > last)
          ++count;
        last = window3;
        window3 = 0;
      }
    }
    ++index;
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
