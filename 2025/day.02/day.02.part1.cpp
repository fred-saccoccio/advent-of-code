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

typedef unsigned long long ull;

bool isValidID(ull n) {
  char buffer[256];
  sprintf(buffer, "%llu", n);
  if(strlen(buffer)%2 != 0) {
    return false;
  }

  string s(buffer);
  size_t halfSize = s.size() / 2;
  string left = s.substr(0, halfSize);
  string right = s.substr(halfSize, halfSize);
  return (left == right);
}

int main (int argc, char *argv[]) {
  string input;
  getline(cin, input);

  ull sum = 0;

  auto rangeSplits = StringSplitter::split(input, ",", false);
  for(auto range:rangeSplits) {
    auto bounds = StringSplitter::split(range, "-", false);
    ull lBound = stoll(bounds[0]);
    ull rBound = stoll(bounds[1]);
    for(ull i = lBound; i <= rBound; i++) {
      if(isValidID(i)) {
        sum += i;
      }
    }
  }

  printf("%llu\n", sum);

  return 0;
}
