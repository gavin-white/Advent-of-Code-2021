#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "driver.h"

#define BOARD_SIZE 5

int is_winner(std::vector<int> board);

void solution(std::ifstream & input) {
  std::string line;
  getline(input, line);
  std::string temp = "";
  std::vector<int> bingo_nums;
  for (char c : line) {
    if (c != ',') {
      temp.push_back(c);
    } else {
      int num = std::stoi(temp);
      bingo_nums.push_back(num);
      temp = "";
    }
  }

  bingo_nums.push_back(std::stoi(temp));

  std::vector<std::vector<int>> boards;

  int next;
  int i = 0;
  while(input >> next) {
    if (i % (BOARD_SIZE * BOARD_SIZE) == 0) {
      boards.push_back(std::vector<int>());
    }
    boards[boards.size() - 1].push_back(next);
    ++i;
  }

  for (int num : bingo_nums) {
    for (int j = 0; j < boards.size(); j++) {
      for (int i = 0; i < boards[j].size(); i++) {
        if (boards[j][i] == num) {
          boards[j][i] = -1;
        }
      }
      int score = is_winner(boards[j]);
      if (score != -1) {
        std::cout << score * num << std::endl;
        return;
      }
    }
  }
}

/*
 * Checks if a board is a bingo winner. If so, returns its score. If not,
 * returns -1.
 */
int is_winner(std::vector<int> board) {
  int score = 0;
  bool overall_flag = false;
  bool flag = true;
  for (int i = 0; i < BOARD_SIZE; i++) { //check rows and add up score
    flag = true;
    for (int j = 0; j < BOARD_SIZE; j++) {
      int cell = board[i * BOARD_SIZE + j];
      if (cell != -1) {
        score += cell;
        flag = false;
      }
    }
    if (flag)
      overall_flag = true;
  }

  for (int i = 0; i < BOARD_SIZE; i++) { // check columns, ignoring score
    flag = true;
    for (int j = 0; j < BOARD_SIZE; j++) {
      int cell = board[j * BOARD_SIZE + i];
      if (cell != -1) 
        flag = false;
    }
    if (flag)
      overall_flag = true;
  }

  if (overall_flag) {
    return score;
  }
  return -1;
}
