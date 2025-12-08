#include <bits/stdc++.h>

using namespace std;

static inline void ltrim(std::string& s) {
  s.erase(s.begin(),
      std::find_if(s.begin(), s.end(),
        [](unsigned char c){ return !std::isspace(c); }));
}

static inline void rtrim(std::string& s) {
    s.erase(
        std::find_if(s.rbegin(), s.rend(),
        [](unsigned char c){ return !std::isspace(c); }).base(),
        s.end());
}

static inline void trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}

int main (int argc, char *argv[]) {
  vector<vector<char>> numbers;
  vector<char> operators;

  char c = '0';

  string input;
  while(getline(cin, input)) {
    char current_char = ' ';
    size_t index = 0;
    vector<char> v;
    
    while(isspace(static_cast<unsigned char>(current_char))) {
      current_char = input[index++];
    }
    
    if(isdigit(static_cast<unsigned char>(current_char))) 
    {
      for(char c:input)
        v.push_back(c);

      numbers.push_back(v);

    } else {
      for(char op:input) {
        if(op == '+' || op == '*'){
          operators.push_back(op);
        }
      }
    }
  }

  unsigned long long int total = 0;
  size_t op_index = operators.size()-1;
  vector<unsigned long long int> terms;
  for(auto col = numbers[0].size()-1; col != -1; col--) {
    string s;
    
    for(auto line = 0; line < numbers.size(); line++) {
      s.push_back(numbers[line][col]);
    }
    trim(s);
    try {
      terms.push_back(stoi(s));
    } catch(...) {
    }
    // printf("|");
    // printf("%s|\n", s.c_str());
    
    if(s == "" || col == 0) {
      unsigned long long int s_total = 0;
      char c_op = operators[op_index--];
      
      if(c_op == '*')
        s_total = 1;

      // printf("Need computation with %c\n", c_op);
      for(auto term:terms) {
        if(c_op == '*')
          s_total *= term;
        else
          s_total += term;
      }

      // printf("s_total=%llu\n", s_total);
      total += s_total;
      // printf("(intermediate) total=%llu\n", total);
      terms.clear();
    }
  }

  printf("%llu\n", total);
  return 0;
}
