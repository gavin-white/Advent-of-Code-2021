#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "driver.h"

void solution(std::ifstream & input) {
  std::string line;
  getline(input, line);
  std::vector<int> quants = std::vector<int>(line.size());
  for (int i = 0; i < quants.size(); i++) {
    quants[i] = line[i] - '0';
  }

  while (getline(input, line)) {
    int i = 0;
    for (char c : line) {
      if (c == '0') {
        quants[i]--;
      } else {
        quants[i]++;
      }
      ++i;
    }
  }
  std::string bnum = "";
  std::string bnum2 = "";
  for (int i : quants) {
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
}
