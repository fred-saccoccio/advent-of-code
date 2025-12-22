#include <bits/stdc++.h>
using namespace std;

void print_grid(vector<vector<char>> grid) {
  for(auto& line:grid) {
    for(char c:line) {
      printf("%c",c);
    }
    printf("\n");
  }
}

size_t hash_cantor(size_t a, size_t b) {
  return ((a+b)*(a+b+1) / 2) + b;
}

size_t timelines(vector<vector<char>> g, 
    size_t line, size_t col, 
    unordered_map<size_t,size_t>& cache) {
 
  if(line == 1)
    return 1;

  // If the searched value is already in the cache, return it without any computation
  size_t key = hash_cantor(line, col); 
  if (cache.find(key) != cache.end()) {
    return cache[key];
  }
 
  size_t ret_val = 0;
  
  // grid[line-1][col-1]=='^' && grid[line-2][col-1]=='|' => timelines(grid, line-2, col-1)
  if(col-1 >= 0) {
    if(g[line-1][col-1] == '^' && g[line-2][col-1] == '|')
      ret_val += timelines(g, line-2, col-1, cache);
  }

  // grid[line-1][col+1]=='^' && grid[line-2][col+1]=='|' => timelines(grid, line-2, col+1)
  if(col+1 < g[line].size()) {
    if(g[line-1][col+1] == '^' && g[line-2][col+1]== '|') {
      ret_val += timelines(g, line-2, col+1, cache);
    }
  }

  // grid[line-1][col]  =='|' && grid[line-2][col]  =='|' => timelines(grid, line-2, col) 
  if(g[line-1][col]  == '|' && g[line-2][col]  == '|') {
    ret_val += timelines(g, line-2, col, cache);
  }

  // Update cache since we computed a new value
  cache[key] = ret_val;

  // retourner valeur calculée
  return ret_val;
}

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

  // print_grid(grid);

  printf("splits=%zu\n", splits);

  size_t timelines_number = 0;
  unordered_map<size_t, size_t> cache;
  // Compute the timelines from each | 
  vector<char>& last_line = grid[grid.size()-1];
  for(size_t col_index = 0; col_index < last_line.size(); col_index++) {
    if(last_line[col_index] == '|') {
      timelines_number += timelines(grid, grid.size()-1, col_index, cache);
    }
  }

  printf("timelines=%zu\n", timelines_number);

  return 0;
}

