#include<bits/stdc++.h>

using namespace std;

class StringSplitter {
  public:
    static std::vector<std::string> split(const std::string& str,
                                          const std::string& delimiters,
                                          bool keepEmpty = false) {
      std::vector<std::string> tokens;
      std::string::size_type pos = 0;
      std::string::size_type prev = 0;
      
      while ((pos = str.find_first_of(delimiters, prev)) != std::string::npos) {
        if (keepEmpty || pos > prev) {
          tokens.push_back(str.substr(prev, pos - prev));
        }
        prev = pos + 1;
      }
      
      if (prev < str.length()) {
        tokens.push_back(str.substr(prev));
      } else if (keepEmpty && prev == str.length()) {
        tokens.push_back("");
      }
      
      return tokens;
  }
};

int main(int argc, char *argv[]) {
  int (*grid)[1000] = new int[1000][1000];
  int nb_lines;

  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();
  
  // Process each line
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);
    auto tokens = StringSplitter::split(line, " ", false);
    
    if(tokens[0] == "turn") {
      
      if(tokens[1] == "on" || tokens[1] == "off") {
        auto top_left_tokens = StringSplitter::split(tokens[2], ",");
        auto down_right_tokens = StringSplitter::split(tokens[4], ",");
        int top_left_x = stoi(top_left_tokens[0]);
        int top_left_y = stoi(top_left_tokens[1]);
        int down_right_x = stoi(down_right_tokens[0]);
        int down_right_y = stoi(down_right_tokens[1]);
        
        if(tokens[1] == "on") {
          for(int line = top_left_x; line <= down_right_x; line++) {
            for(int col = top_left_y; col <= down_right_y; col++) {
              grid[line][col] += 1;
            }
          }
        } else {
          for(int line = top_left_x; line <= down_right_x; line++) {
            for(int col = top_left_y; col <= down_right_y; col++) {
              grid[line][col] = max(0, grid[line][col] - 1);
            }
          }
        }

      }
      
    }
    
    if(tokens[0] == "toggle") {
      auto top_left_tokens = StringSplitter::split(tokens[1], ",");
      auto down_right_tokens = StringSplitter::split(tokens[3], ",");
      int top_left_x = stoi(top_left_tokens[0]);
      int top_left_y = stoi(top_left_tokens[1]);
      int down_right_x = stoi(down_right_tokens[0]);
      int down_right_y = stoi(down_right_tokens[1]);
        
      for(int line = top_left_x; line <= down_right_x; line++) {
        for(int col = top_left_y; col <= down_right_y; col++) {
          grid[line][col] += 2;
        }
      }
    }

  }

  unsigned long long int lights_on = 0;
  for(int line = 0; line < 1000; line++) {
    for(int col = 0; col < 1000; col ++) {
      lights_on += grid[line][col];
    }
  } 

  printf("%lld\n", lights_on);
  
  delete[] grid; // free memory

  return 0;
}

