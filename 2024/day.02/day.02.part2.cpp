#include <bits/stdc++.h>
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
bool level_is_safe(vector<int>& l) {
  bool ret_val = true;
  bool increasing = false;
  
  if(l[0] > l[1])
    increasing = false;
  else 
    increasing = true;

  size_t max_level = l.size() - 1;
  
  int delta = 0;
  for(size_t index = 0; index < max_level; index++) {
    if((l[index] < l[index+1]) && (increasing == false))
      return false;
    if(increasing)
      delta = l[index+1] - l[index];
    else {
      delta = l[index] - l[index+1];
    }

    if(delta < 1 || delta > 3) {
      return false;
    }
  }

  return ret_val;
}

int main (int argc, char *argv[]) {

  unsigned long long int safe_number = 0;
  string input;
  while(getline(cin, input)) {
    auto splits = StringSplitter::split(input, " ");
    vector<int> level;
    for(auto split:splits) {
      level.push_back(stoi(split));
    }

    bool is_safe = false;
    for(size_t i = 0; i < level.size(); i++) {
      vector<int> v = level;
      v.erase(v.begin() + i);
      if(level_is_safe(v)) {
        is_safe = true;
        break;
      }
    }

    if(is_safe || level_is_safe(level))
      safe_number++;
  }

  printf("safe=%llu\n",safe_number);
 
  return 0;
}
