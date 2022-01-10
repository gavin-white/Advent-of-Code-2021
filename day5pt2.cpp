#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "driver.h"

struct Line {
  int x1;
  int x2;
  int y1;
  int y2;

  bool vert() {
    return x1 == x2;
  }

  bool horiz() {
    return y1 == y2;
  }

  bool diag() {
    return y1 != y2 && x1 != x2;
  }
};

void solution(std::ifstream & input) {
  int max_x = 0;
  int max_y = 0;
  std::vector<Line> lines;

  std::string line;
  Line next;
  while (getline(input, line)) {
    std::stringstream s = std::stringstream(line);
    char delim = '\0';
    s >> next.x1 >> delim >> next.y1 >> delim >> delim >> next.x2 >> delim >> next.y2;
    if (next.x1 > max_x) max_x = next.x1;
    if (next.x2 > max_x) max_x = next.x2;
    if (next.y1 > max_y) max_y = next.y1;
    if (next.y2 > max_y) max_y = next.y2;
    lines.push_back(next);
  }

  std::vector<std::vector<int>> grid = std::vector<std::vector<int>>(max_y + 1, std::vector<int>(max_x + 1, 0));

  int total = 0;
  for (Line l : lines) {
    if (l.vert()) {
      int i = l.y1 > l.y2 ? l.y2 : l.y1;
      int end = l.y1 < l.y2 ? l.y2 : l.y1;
      for (; i <= end; i++) {
        if (grid[i][l.x1] == 1) {
          total++;
        }
        grid[i][l.x1]++;
      }
    } else if (l.horiz()) {
      int i = l.x1 > l.x2 ? l.x2 : l.x1;
      int end = l.x1 < l.x2 ? l.x2 : l.x1;
      for (; i <= end; i++) {
        if (grid[l.y1][i] == 1) {
          total++;
        }
        grid[l.y1][i]++;
      }
    } else if (l.diag()) {
      for (int i = 0; l.x1 < l.x2 ? l.x1 + i < l.x2 : l.x2 + i < l.x1; i++) {
        if (grid[l.y])
      }
    }
  }

  std::cout << total << std::endl;
}

