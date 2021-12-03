#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void solution(std::ifstream & input) {
  std::string line;
  getline(input, line);
  std::vector<int>* quants = new std::vector<int>(line.size());
  for (int i : *quants) {
    i = 0;
  }

  while (getline(input, line)) {
    int i = 0;
    for (char c : line) {
      if (c == '0') {
        (*quants)[i]--;
      } else {
        (*quants)[i]++;
      }
      ++i;
    }
  }
  std::string bnum = "";
  std::string bnum2 = "";
  for (int i : *quants) {
    if (i > 0) {
      bnum.append("1");
      bnum2.append("0");
    } else  {
      bnum.append("0");
      bnum2.append("1");
    }
  }

  unsigned short num = std::stoi(bnum, nullptr, 2);
  unsigned short num2 = std::stoi(bnum2, nullptr, 2);
  
  std::cout << num * num2 << std::endl;
  delete quants;
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
