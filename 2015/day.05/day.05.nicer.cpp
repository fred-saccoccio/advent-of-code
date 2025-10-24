#include<bits/stdc++.h>
using namespace std;


bool is_nicer(string s) {
  bool ret_val = false;
  size_t length = s.length();
  unsigned int matched_double_vowels = 0;
  unsigned int matched_three_overlap = 0;

  for(int i = 0; i < length - 1; i++) {

    // Loop before
    for(int j = 0; j < i - 1; j++) {
      if(memcmp(s.c_str() + i, s.c_str() + j, 2) == 0) {
        matched_double_vowels++;
        break;
      }
    }

    // Loop after
    for(int j = i + 2; j < length - 1; j++) {
      if(memcmp(s.c_str() + i, s.c_str() + j, 2) == 0) {
        matched_double_vowels++;
        break;
      }
    }
  }


  for(size_t i = 0; i < length - 2; i++) {
    if(s[i] == s[i+2]) {
      matched_three_overlap++;
    }
  }

  if(matched_double_vowels > 0 && matched_three_overlap > 0) {
    ret_val = true;
  }

  return ret_val;
}

int main (int argc, char *argv[]) {
  int nb_lines = 0;
  int nice_lines = 0;
  
  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();
  
  // Process each line
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);
    if(is_nicer(line)) {
      printf("%s\n", line.c_str());
      nice_lines++;
    }
  }

  cout << nice_lines << endl;

  return 0;
}

