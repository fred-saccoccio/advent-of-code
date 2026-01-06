#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  vector<vector<char>> DataGrid;
  
  string Input;
  while(getline(cin, Input)) {
    vector<char> Line;
    for(char c:Input) {
      Line.push_back(c);
    }
    DataGrid.push_back(Line);
  }

  const size_t COLUMNS = DataGrid[0].size();
  const size_t LINES = DataGrid.size();

  unsigned long long int XmasCountPart1 = 0;

  // Search for "XMAS" or "SAMX" horizontally
  for(size_t line = 0; line < LINES; line++) {
    for(size_t col = 0; col < (COLUMNS-3); col++) {
      if(    DataGrid[line][col]   == 'X' 
          && DataGrid[line][col+1] == 'M' 
          && DataGrid[line][col+2] == 'A' 
          && DataGrid[line][col+3] == 'S') {
        XmasCountPart1++;
      }
      
      if(    DataGrid[line][col]   == 'S' 
          && DataGrid[line][col+1] == 'A' 
          && DataGrid[line][col+2] == 'M' 
          && DataGrid[line][col+3] == 'X') {
        XmasCountPart1++;
      }
    }
  }
  
  // Search for 'X' or 'S' vertically
  //            'M'    'A'
  //            'A'    'M'
  //            'S'    'X'
  for(size_t line = 0; line < (LINES-3); line++) {
    for(size_t col = 0; col < COLUMNS; col++) {
      if(    DataGrid[line  ][col] == 'X' 
          && DataGrid[line+1][col] == 'M' 
          && DataGrid[line+2][col] == 'A' 
          && DataGrid[line+3][col] == 'S') {
        XmasCountPart1++;
      }
      
      if(    DataGrid[line  ][col] == 'S' 
          && DataGrid[line+1][col] == 'A' 
          && DataGrid[line+2][col] == 'M' 
          && DataGrid[line+3][col] == 'X') {
        XmasCountPart1++;
      }
    }
  }
  
  // Search for 'X'    or 'S'    in descending diagonal
  //             'M'       'A'
  //              'A'       'M'
  //               'S'       'X'
  for(size_t line = 0; line < (LINES-3); line++) {
    for(size_t col = 0; col < (COLUMNS-3); col++) {
      if(    DataGrid[line  ][col  ] == 'X'
          && DataGrid[line+1][col+1] == 'M'
          && DataGrid[line+2][col+2] == 'A'
          && DataGrid[line+3][col+3] == 'S') {
        XmasCountPart1++;
      }
      
      if(    DataGrid[line  ][col  ] == 'S'
          && DataGrid[line+1][col+1] == 'A'
          && DataGrid[line+2][col+2] == 'M'
          && DataGrid[line+3][col+3] == 'X') {
        XmasCountPart1++;
      }
    }
  }
  // Search for    'X' or    'S'    in ascending diagonal
  //              'M'       'A'
  //             'A'       'M'
  //            'S'       'X'
  for(size_t line = 0; line < (LINES-3); line++) {
    for(size_t col = 0; col < (COLUMNS-3); col++) {
      if(    DataGrid[line  ][col+3] == 'X'
          && DataGrid[line+1][col+2] == 'M'
          && DataGrid[line+2][col+1] == 'A'
          && DataGrid[line+3][col  ] == 'S') {
        XmasCountPart1++;
      }

      if(    DataGrid[line  ][col+3] == 'S'
          && DataGrid[line+1][col+2] == 'A'
          && DataGrid[line+2][col+1] == 'M'
          && DataGrid[line+3][col  ] == 'X') {
        XmasCountPart1++;
      }
    }
  }

  printf("XMAS count, part 1=%llu\n", XmasCountPart1);
  
  unsigned long long int XmasCountPart2 = 0;
  
  for(size_t line = 0; line < (LINES-2); line++) {
    for(size_t col = 0; col < (COLUMNS-2); col++) {
      if(DataGrid[line+1][col+1] == 'A') {
        if(    (DataGrid[line][col] == 'M' && DataGrid[line+2][col+2] == 'S') 
            || (DataGrid[line][col] == 'S' && DataGrid[line+2][col+2] == 'M')) {
          if(    (DataGrid[line][col+2] == 'M' && DataGrid[line+2][col] == 'S')
              || (DataGrid[line][col+2] == 'S' && DataGrid[line+2][col] == 'M')) {
            XmasCountPart2++;
          }
        }
      }
    }
  }

  printf("XMAS count, part 2=%llu\n", XmasCountPart2);
  
  return 0;
}
