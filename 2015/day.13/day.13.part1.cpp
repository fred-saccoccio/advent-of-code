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

class DinerProblem {
  int costs[32][32];
  unordered_map<string, int> names_str_to_int;
  vector<string> names;
  public:
  void load_input();
  void solve_brute_force();
  
  DinerProblem() {     // Constructor
    memset(costs, 0, sizeof(costs));
  }
};

  

void DinerProblem::load_input() {
  int nb_lines;

  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();
 
  // Process each line
  int current_name_index = 0;
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);

    cout << "Processing |" << line << "|" << endl; 
    
    // Remove trailing period
    line.pop_back();

    auto tokens = StringSplitter::split(line, " ", false);
    
    int name_indexes[] = {0, 10};
    
    // Parse names
    for(auto index:name_indexes) {
      string key = tokens[index];
      
      if(names_str_to_int.find(key) == names_str_to_int.end()) {
        // Process an unknown location
        names_str_to_int[key]= current_name_index;

        names.push_back(key);

        cout << "Matched new name #" 
          << current_name_index 
          << " : "<< key << " => "; 
        
          current_name_index++;
      }
    } // End of parse names

    // Check if happiness is gained or lost
    int happinessFactor = 1;
    if(tokens[2] == "lose") {
      // Happiness is lost
      happinessFactor = -1;
    } else {
      // Happiness is gained 
      happinessFactor = 1;
    }


    // Parse the #3 token as the cost and insert it the the costs matrix
    int cost = happinessFactor * stoi(tokens[3]);
    int name1_index = names_str_to_int[tokens[0]];
    int name2_index = names_str_to_int[tokens[10]];
    costs[name1_index][name2_index] = cost;
    printf("costs[%d][%d] <- %d\n", 
        name1_index, name2_index, 
        cost);
    cout << "--------------------------------------------------------------------------------" << endl;
  }

  printf("costs matrix:\n");
  int N = names.size();
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

void DinerProblem::solve_brute_force() {
  cout << "names:" << endl;
  int index = 0;
  for(auto x:names) {
    printf("[%d]=%s\n", index++, x.c_str());
  }

  cout << "names_str_to_int:" << endl;
  for(auto y:names_str_to_int) {
    cout << "[" << y.first << "]=" << y.second << endl;
  }

  vector<int> people;
  for(int i = 0; i < (int)names.size(); i++) {
    people.push_back(i);
  }

  int max = INT_MIN;
  int N = people.size();
  do {
    print(people);
    int computedHappiness = 0;
    for(int index = 0; index < N - 1; index++) {
      computedHappiness += costs[people[index]][people[index+1]];
      computedHappiness += costs[people[index+1]][people[index]];
    }

    // Close the loop by taking fisrt and last people in the list
    computedHappiness += costs[people[0]][people[N-1]];
    computedHappiness += costs[people[N-1]][people[0]];


    if(computedHappiness >= max) {
      max = computedHappiness;
    }
  } while ( std::next_permutation(people.begin(), people.end()) );
 
  printf("brute force max = %d\n", max);
}

int main(int argc, char *argv[]) {
  DinerProblem p;
  
  p.load_input();
  p.solve_brute_force();

  // test();
}
