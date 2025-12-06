#include <bits/stdc++.h>

using namespace std;

void printGrid(vector<vector<char>> g) {
  for(auto line:g) {
    for(auto c:line) {
      printf("%c",c);
    }
    printf("\n");
  }
}

int main (int argc, char *argv[]) {
  int nbLines = 0;
  cin >> nbLines;
  cin.ignore();

  bool firstLine = true;
  vector<vector<char>> grid;
  size_t s = 0;

  for(int i = 0; i < nbLines; i++) {
    string input;
    getline(cin, input);
    
    if(firstLine) {
      vector<char> tmp;
      s = input.size() + 2;
      for(size_t i = 0; i < s; i++) {
        tmp.push_back('.');
      }
      grid.push_back(tmp);
      firstLine = false;
    }

    vector<char> l;
    l.push_back('.');
    for(char c:input) {
      l.push_back(c);
    }
    l.push_back('.');
    grid.push_back(l);
  }

  // Last line of the grid
  vector<char> tmp;
  for(size_t i = 0; i < s; i++) {
    tmp.push_back('.');
  }
  grid.push_back(tmp);

  // printGrid(grid);
  unsigned long long int totalRemoved = 0;

  size_t linesToProcess = grid.size() - 2;
  size_t colsToProcess = grid[0].size() - 2;
  bool rollsCanBeRemoved = true;
  while(rollsCanBeRemoved) {
    unsigned long long int removedInLoop = 0;
    for(size_t line = 1; line <= linesToProcess; line++) {
      for(size_t col = 1; col <= colsToProcess; col++) {
        if(grid[line][col] != '@')
          continue;

        size_t adjacent_rolls = 0;
        
        // Upper line
        for(size_t i = 0; i < 3; i++) {
          if(grid[line-1][col-1+i] == '@') {
            adjacent_rolls++;
          }
        }
        
        // Curent line
        if(grid[line][col - 1] == '@') {
          adjacent_rolls++;
        }
        if(grid[line][col + 1] == '@') {
          adjacent_rolls++;
        }

        // Under line
        for(size_t i = 0; i < 3; i++) {
          if(grid[line+1][col-1+i] == '@') {
            adjacent_rolls++;
          }
        }
      
        if(adjacent_rolls < 4) {
          totalRemoved++;
          removedInLoop++;
          grid[line][col] = '.';
          // printf("[%lu,%lu] is OK\n", line, col);
        }
      }
    }
    if(removedInLoop == 0)
      rollsCanBeRemoved = false;
  }

  printf("%llu\n", totalRemoved);

  return 0;
}

