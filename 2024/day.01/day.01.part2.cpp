#include <bits/stdc++.h>
using namespace std;
const size_t MAX_LIST=1000; 

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

int main (int argc, char *argv[]) {
  vector<int> left;
  //vector<int> right;
  unordered_map<int,int> right;
  
  string input;
  while(getline(cin, input)) {
    auto splits = StringSplitter::split(input, " ");
    left.push_back(stoi(splits[0]));
    int r = stoi(splits[1]);
    
    if (right.find(r) != right.end()) {
    // la clé existe
       right[r]++;
    } else {
      right[r] = 1;
    }
  }
  
  unsigned long long int sim_score = 0;
  for(auto l:left) {
    if(right.find(l) != right.end())
      sim_score += l*right[l];
  }
 
  printf("sim_score=%llu\n", sim_score);

  return 0;
}
