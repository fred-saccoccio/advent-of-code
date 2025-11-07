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

class TspProblem {
  int costs[128][128];
  unordered_map<string, int> locations_str_to_int;
  vector<string> locations;
  public:
  void load_input();
  void solve_brute_force();
};

void TspProblem::load_input() {
  int nb_lines;

  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();
 
  // Process each line
  int current_location_index = 0;
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);

    cout << "Processing |" << line << "|" << endl; 

    auto tokens = StringSplitter::split(line, " ", false);
    
    int index = 0;
    int cities[] = {0, 2};
    for(auto index:cities) {
      string key = tokens[index];
      
      if(locations_str_to_int.find(key) == locations_str_to_int.end()) {
        // Process an unknown location
        locations_str_to_int[key]= current_location_index;

        locations.push_back(key);

        cout << "Matched new location #" 
          << current_location_index 
          << " : "<< key << " => "; 
        
          current_location_index++;
      }
    }

    // Parse the last token as an int and insert it the the costs matrix
    int cost = stoi(tokens[4]);
    int loc1_index = locations_str_to_int[tokens[0]];
    int loc2_index = locations_str_to_int[tokens[2]];
    costs[loc1_index][loc2_index] = cost;
    costs[loc2_index][loc1_index] = cost;
    printf("costs[%d][%d]=costs[%d][%d] <- %d\n", 
        loc1_index, loc2_index, 
        loc2_index, loc1_index, 
        cost);
    cout << "--------------------------------------------------------------------------------" << endl;
  }

  printf("costs matrix:\n");
  int N = locations.size();
  for(int line = 0; line < N; line++) {
    for(int col = 0; col < N; col++) {
      printf("% 8d", costs[line][col]);
    }
    cout << endl;
  }
}

void print(const std::vector<int>& v) {
  for (int e : v) {
    std::cout << " " << e;
  }
  
  std::cout << std::endl;
}

void TspProblem::solve_brute_force() {
  cout << "locations:" << endl;
  int index = 0;
  for(auto x:locations) {
    printf("[%d]=%s\n", index++, x.c_str());
  }

  cout << "locations_str_to_int:" << endl;
  for(auto y:locations_str_to_int) {
    cout << "[" << y.first << "]=" << y.second << endl;
  }

  vector<int> locs;
  for(int i = 0; i < locations.size(); i++) {
    locs.push_back(i);
  }

  int max = INT_MIN;
  int N = locs.size();
  do {
    print(locs);
    int travel = 0;
    for(int index = 0; index < N - 1; index++) {
      travel += costs[locs[index]][locs[index+1]];
    }
    if(travel >= max) {
      max = travel;
    }
  } while ( std::next_permutation(locs.begin(), locs.end()) );
 
  printf("brute force min = %d\n", max);
}


int test() {
  std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7};
  // vector should be sorted at the beginning.
          
  do {
    print(v);
  } while (std::next_permutation(v.begin(), v.end()));

  return 0;
}


int main(int argc, char *argv[]) {
  TspProblem p;
  
  p.load_input();
  p.solve_brute_force();

  // test();
}
