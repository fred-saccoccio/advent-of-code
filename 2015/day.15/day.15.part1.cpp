#include <bits/stdc++.h>

using namespace std;

typedef struct _Ingredient {
  string Name;
  int Capacity;
  int Durability;
  int Flavor;
  int Texture;
  int Calories;
  void print();
  void println();
} Ingredient;

void Ingredient::print() {
  printf("{.Name=\"%s\", .Capacity=%d, .Durability=%d, .Flavor=%d, .Texture=%d, .Calories=%d}",
      Name.c_str(), Capacity, Durability, Flavor, Texture, Calories);
}

void Ingredient::println() {
  print();
  printf("\n");
}

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

void printVector(vector<int> v) {
  printf("[");

  for(size_t i = 0; i < v.size(); i++) {
    printf("%d", v[i]);
    if(i != v.size() - 1) {
      printf(",");
    }
  }

  printf("]");
}

template <typename T> vector<vector<T>> getSubsets(vector<T>& v) {
  vector<vector<T>> retVal;  
  if(v.size() == 0) {
    vector<T> empty;
    retVal.push_back(empty);
    return retVal;
  }

  // NOTE : v.size() > 0 at this point
  
  // Recursively call getSubsets on v minus its last element
  vector<T> recCallSet = { v.begin(), v.end()-1 };
  vector<vector<T>> recCallSubsets = getSubsets(recCallSet);

  // Build the return value by combining :
  // 1. The recursive call on the set of v's n-1 first elements
  // 2. All the elements of the recursive call where we add v's last element
  for(auto& e:recCallSubsets) {
    retVal.push_back(e);
  }
 
  int elt = v.back();
  for(auto& e:recCallSubsets) {
    vector<int> a = e;
    a.push_back(elt);
    retVal.push_back(a);
  }

  return retVal;
}

vector<vector<unsigned int>> getPartitions(unsigned int n) {
  vector<vector<unsigned int>> retVal;
  return retVal;
}

int main (int argc, char *argv[]) {
  
  vector<Ingredient> ingredients;

  int nb_lines;

  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();
 
  // Process each line
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);

    auto splits = StringSplitter::split(line, ":", false);
    Ingredient ing;
    ing.Name = splits[0];

    auto allCharacteristics = StringSplitter::split(splits[1], ",", false);
    
    auto capSplits = StringSplitter::split(allCharacteristics[0], " ", false);
    ing.Capacity = stoi(capSplits[1]);
    
    auto durSplits = StringSplitter::split(allCharacteristics[1], " ", false);
    ing.Durability = stoi(durSplits[1]);

    auto flavSplits = StringSplitter::split(allCharacteristics[2], " ", false);
    ing.Flavor = stoi(flavSplits[1]);

    auto textSplits = StringSplitter::split(allCharacteristics[3], " ", false);
    ing.Texture = stoi(textSplits[1]);

    auto calSplits = StringSplitter::split(allCharacteristics[4], " ", false);
    ing.Calories = stoi(calSplits[1]);

    ingredients.push_back(ing);
  }

  for(auto& i:ingredients) {
    i.println();
  }

  vector<int> data;
  for(int i = 0; i < 6; i++) {
    data.push_back(i);
  }
  printVector(data);
  printf("\n");
  printf("data.size()=%zu\n", data.size());

  auto subsets = getSubsets<int>(data);
  printf("[");
  printf("\n");
  for(auto& s:subsets) {
    printf("  ");
    printVector(s);
    printf("\n");
  }
  printf("]");
  printf("\n");
  printf("subsets.size()=%zu\n", subsets.size());

  return 0;
}
