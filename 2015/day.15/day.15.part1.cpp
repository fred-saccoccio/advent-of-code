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

  return 0;
}
