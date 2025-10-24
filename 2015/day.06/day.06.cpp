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
  char grid[1000][1000] = {0};
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
      }
      
    }
    
    if(tokens[1] == "toggle") {
      auto top_left_tokens = StringSplitter::split(tokens[1], ",");
      auto down_right_tokens = StringSplitter::split(tokens[3], ",");
      int top_left_x = stoi(top_left_tokens[0]);
      int top_left_y = stoi(top_left_tokens[1]);
      int down_right_x = stoi(down_right_tokens[0]);
      int down_right_y = stoi(down_right_tokens[1]);
    }
    
//    for (size_t i = 0; i < tokens.size(); ++i) {
//      std::cout << "Token " << i << ": '" << tokens[i] << "'" << std::endl;
//    }
    
    printf("\n");
    
  }
  
  return 0;
}

