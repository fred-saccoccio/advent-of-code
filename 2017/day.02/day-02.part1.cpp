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

int main (int argc, char *argv[]) {
  // Stdin/stdout optimizations => quicker i/o for competitive programming
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string line;
  long long int checksum = 0;
  while (getline(cin, line)) {
    auto splits = StringSplitter::split(line, "\t");
    long long int the_min = LLONG_MAX;
    long long int the_max = LLONG_MIN;
    for(auto& s:splits) {
      long long int val = stoll(s);
      if(val < the_min)
        the_min = val;
      if(val> the_max)
        the_max = val;
    }
    checksum += (the_max - the_min);
  }

  cout << checksum << "\n";
  
  return 0;
}
