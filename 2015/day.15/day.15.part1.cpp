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

template<typename T>
void printVector(vector<T> v) {
  printf("[");

  for(size_t i = 0; i < v.size(); i++) {
    printf("%d", v[i]);
    if(i != v.size() - 1) {
      printf(",");
    }
  }

  printf("]");
}

template<>
void printVector<unsigned int>(vector<unsigned int> v) {
  printf("[");

  for(size_t i = 0; i < v.size(); i++) {
    printf("%u", v[i]);
    if(i != v.size() - 1) {
      printf(",");
    }
  }

  printf("]");
}


template <typename T> 
vector<vector<T>> getSubsets(vector<T>& v) {
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
  
  vector<unsigned int> v;
  v.push_back(n);
  retVal.push_back(v);

  if(n == 0) {
    return retVal;
  }

  bool finished = false;
  vector<unsigned int>& currentPartition = v;
  while(! finished) {
    
    // Find the rightmost element and different from 1 in currentPartition
    // We refer it as the pivot hereafter
    int index = currentPartition.size() - 1;
    int remainder= 0;
    while(index >= 0 && currentPartition[index] == 1) {
      remainder++;
      index--;
    }

    if(index < 0) {
      finished = true;
      break;
    }

    int pivot = currentPartition[index];
    vector<unsigned int> tmpPartition; 
    for(size_t i = 0; i < (size_t)index; i++) 
    {
      tmpPartition.push_back(currentPartition[i]); 
    }
    pivot--; // decrement pivot
    tmpPartition.push_back(pivot);
    remainder++;
    
    // Now distribute remainder by chunks of pivot
    unsigned int chunkNumbers = remainder / pivot;
    unsigned int chunkRemainder = remainder % pivot;
    for(size_t i=0; i < chunkNumbers; i++) {
      tmpPartition.push_back(pivot);
    }

    if(chunkRemainder > 0) {
      tmpPartition.push_back(chunkRemainder);
    }
    
    retVal.push_back(tmpPartition);
    
    currentPartition = retVal.back();
  }
 
  return retVal;
}

vector<unsigned int> ones(size_t s) {
  vector<unsigned int> retVal;
  for(size_t i = 0; i < s; i++) {
    retVal.push_back(1);
  }
  return retVal;
}

vector<unsigned int> combine(unsigned int n, vector<unsigned int>v) {
 vector<unsigned int> retVal;
 retVal.push_back(n);
 for(auto& e:v) {
   retVal.push_back(e);
 }
 return retVal;
}

vector<vector<unsigned int>> combine(unsigned int n, vector<vector<unsigned int>>v) {
 vector<vector<unsigned int>> retVal;
 for(auto& e:v) {
   retVal.push_back(combine(n, e));
 }
 return retVal;
}


vector<vector<unsigned int>> distribute(unsigned int N, unsigned int m, unsigned int maxCell = UINT_MAX) {

  // printf("\tcall distribute(%u, %u)\n", N, m);
  vector<vector<unsigned int>> retVal;
  
  if(N < m){
    return retVal;
  }
  
  if(N == m) {
    auto v = ones(N);
    retVal.push_back(v);
    return retVal;
  }

  if(m == 1) {
    vector<unsigned int> v;
    v.push_back(N);
    retVal.push_back(v);
    return retVal;
  }

  unsigned int firstCellMinSize = N / m;
  firstCellMinSize += ( (N%m == 0) ? 0 : 1 );
  unsigned int firstCellMaxize = min(N - (m-1), maxCell);

  // if we have to process distribute(100, 6)
  // combine 95 with distribute(5, 5) and add it to retVal
  // combine 94 with distribute(6, 5)  and add it to retVal
  // combine 93 with distribute(7, 5)  and add it to retVal
  // ...
  // combine 18 with distribute(82, 5)  and add it to retVal
  // combine 17 with distribute(83, 5)  and add it to retVal
  for(unsigned int i = firstCellMaxize; i >= firstCellMinSize; i--) {
    vector<vector<unsigned int>> subCallRes = distribute(N-i, m-1, i);
    for(vector<unsigned int> res:subCallRes) {
      vector<unsigned int> combination = combine(i, res);
      retVal.push_back(combination);
    }
  }
  
  return retVal;
}

int main (int argc, char *argv[]) {
  
  vector<Ingredient> ingredients;

  int nb_lines;


  /*****
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
  *****/

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
    printVector<int>(s);
    printf("\n");
  }
  printf("]");
  printf("\n");
  printf("subsets.size()=%zu\n", subsets.size());

  /*
  auto parts = getPartitions(100);
  for(auto& p:parts) {
    printVector<unsigned int>(p);
    printf("\n");
  }
  */

  unsigned int N;
  unsigned int m;
  cin >> N >> m;

  for(unsigned int i = 1; i <= m; i++) {
    auto dist = distribute(N, i);
    printf("[");
    printf("\n");
    for(auto& d:dist) {
      printf("  ");
      printVector<unsigned int>(d);
      printf("\n");
    }
    printf("]");
    printf("\n");
  }
  
  return 0;
}
