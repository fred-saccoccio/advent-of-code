#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  vector<vector<char>> grid;

  // Read input data
  string input;
  while(getline(cin, input)) {
    vector<char> v;
    for(char c:input) {
      v.push_back(c);
    }
    grid.push_back(v);
  }

  // Process start line : add a beam under the 'S' char
  size_t index = 0;
  
  for(char c:grid[0]) {
    if(c == 'S')
      break;
    index++;
  }
  
  if(index == grid[0].size())
    cout << "No start (S) in the first line\n";
  
  grid[1][index] = '|';

  size_t splits = 0;
  size_t LINES = grid.size();
  size_t COLS = grid[0].size();
  for(size_t line = 1; line < LINES-1; line++) {
    for(size_t col = 0; col < COLS; col++) {
      // Beam here ?
      if(grid[line][col] == '|') {
        if(grid[line+1][col] == '.' ) {
          // Beam moves forward
          grid[line+1][col] = '|'; 
        } else if(grid[line+1][col] == '^' ) {
          int local_splits = 0;
          // Split the beam : Left
          if((int)col-1 >= 0) {
            grid[line+1][col - 1] = '|';
            local_splits++;
          }
          // Split the beam : Left
          if(col+1 < COLS) {
            grid[line+1][col + 1] = '|';
            local_splits++;
          }
          if(local_splits==2)
            splits++;
        }
      }
    }
  }

  printf("splits=%zu\n", splits);
  return 0;
}
