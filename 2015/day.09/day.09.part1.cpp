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


void print(const std::vector<int>& v) {
  for (int e : v) {
    std::cout << " " << e;
  }
  
  std::cout << std::endl;
}

int test() {
  std::vector<int> v = {0, 1, 2, 3, 4, 5, 6 , 7};
  // vector should be sorted at the beginning.
          
  do {
    print(v);
  } while (std::next_permutation(v.begin(), v.end()));

  return 0;
}


int main(int argc, char *argv[]) {
  int nb_lines;

  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();
 
  unordered_set<string> locations;
  // Process each line
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);
    auto tokens = StringSplitter::split(line, " ", false);
    int index = 0;
    for(auto tok:tokens) {
      cout << index++ << "=>" << tok << endl;
    }
    locations.insert(tokens[0]);
    locations.insert(tokens[2]);
  }

  cout << "Locations :" << endl;
  for(auto loc:locations) {
    cout << loc << endl;
  }

  test();
}
