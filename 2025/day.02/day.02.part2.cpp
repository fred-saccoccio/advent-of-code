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
  // printf("isValidID(%llu)\n", n);
  bool retVal = false;
  char buffer[256];
  sprintf(buffer, "%llu", n);

  string s(buffer);

  size_t sSize = s.size(); 
  size_t upperBound = n;//; ceil(sqrt(sSize)); 
  
  for(size_t i = 1; i < sSize; i++) {
    // printf("Trying chunk of size %zu\n", i);
    if(sSize % i == 0) { // s can be chunked into (sSize/i) chunks of size i
      size_t chunksNumber = sSize/i;
      vector<string> chunks;
      for(size_t j = 0; j < chunksNumber; j += 1)  {
        string chunk = s.substr(j*i, i);
        chunks.push_back(chunk);
        // printf("chunk = |%s|\n", chunk.c_str());
      }
     
      size_t comparisons = 0;
      for(size_t j = 0; j < chunks.size()-1; j++) {
        if(chunks[j] == chunks[j+1]) {
          comparisons++;
        }
      }

      if( (comparisons > 0) && (comparisons == chunks.size()-1) ) {
        retVal = true;
        break;
      }
    }
  }

  return retVal;
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
    // printf("processing range [%llu,%llu]\n", lBound, rBound);
    for(ull i = lBound; i <= rBound; i++) {
      if(isValidID(i)) {
        //printf("\t%llu is valid\n", i);
        sum += i;
      }
    }
  }

  printf("%llu\n", sum);

  return 0;
}
