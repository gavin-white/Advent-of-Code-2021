#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "driver.h"

void solution(std::ifstream & input) {
  std::string line;
  getline(input, line);
  for (int i = 0; i < line.size(); i++) {
    if (line[i] == ',') {
      line[i] = ' ';
    }
  }
  std::stringstream s = std::stringstream(line);
  int max_val = 0;
  std::vector<int> nums;
  int next;
  while (s >> next) {
    if (next > max_val) max_val = next;
    nums.push_back(next);
  }

  std::vector<int> totals = std::vector<int>(max_val + 1, 0);
  for (int i = 0; i < totals.size(); i++) {
    for (int num : nums) {
      totals[i] += (abs(num - i) * (abs(num - i) + 1) / 2);
      // this uses the formula for the sum of the first n natural numbers
      // where n = abs(num - i)
    }
  }

  std::cout << *min_element(totals.begin(), totals.end()) << std::endl;
}
