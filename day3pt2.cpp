#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int filter(std::vector<std::string> & numbers, char(*keeper)(int));

void solution(std::ifstream & input) {
  std::string line;
  std::vector<std::string> numbers;
  std::vector<std::string> numbers2;

  while (getline(input, line)) {
    numbers.push_back(line);
    numbers2.push_back(line);
  }

  std::cout << (
    filter(numbers, [] (int q) {if (q >= 0) return '1'; return '0';}) * 
    filter(numbers2, [] (int q) {if (q >= 0) return '0'; return '1';})) << std::endl;
}

/*
 * Filters out the numbers repeatedly based on the specification until only
 * 1 remains. The input vector is the list to filter. The input fn is the
 * bit criteria. Returns the final value in decimal.
 */
int filter(std::vector<std::string> & numbers, char(*keeper)(int)) {
  int bitlen = numbers[0].size();
  while (numbers.size() > 1) {
    for (int i = 0; ; ++i %= bitlen) {
      int quant = 0;
      for (std::string num : numbers) {
        num[i] == '1' ? quant++ : quant--;
      }
      char keep = keeper(quant);
      for (auto it = numbers.begin(); it != numbers.end(); it++) {
        if ((*it)[i] != keep)  {
          numbers.erase(it);
          it--;
        }
      }
      if (numbers.size() == 1) 
        break;
    }
  }
  return stoi(numbers[0], nullptr, 2);
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
