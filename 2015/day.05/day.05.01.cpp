#include<bits/stdc++.h>
using namespace std;

bool is_forbidden(char s[2]) {
  // "ab"
  if(s[0] == 'a' && s[1] == 'b')
    return true;

  // "cd"
  if(s[0] == 'c' && s[1] == 'd')
    return true;
  
  // "pq"
  if(s[0] == 'p' && s[1] == 'q')
    return true;
  
  // "xy"
  if(s[0] == 'x' && s[1] == 'y')
    return true;

  return false;
}

bool is_nice(string s) {
  bool ret_val = false;
  char current_char;
  char frame[2] = {'#', '#'};
  unsigned int nb_vowels = 0;
  size_t length = s.length();
  unsigned int twice_in_a_row = 0;
  bool forbidden_matched = false;

  for(size_t i = 0; i < length; i++) {
    current_char = s[i];
    
    // Check vowels
    if(   current_char == 'a'
       || current_char == 'e'
       || current_char == 'i'
       || current_char == 'o'
       || current_char == 'u' ) {
      nb_vowels++;
    }
    
    // Update frame[]
    frame[1] = current_char;
    if(i > 0) {
      frame[0] = s[i-1];
    }

    // Check for forbidden strings
    if(is_forbidden(frame)) {
      forbidden_matched = true;
      break;
    }
    
    // Check for twice in row
    if(frame[0] == frame[1]) {
      twice_in_a_row++;
    }
  }

  if(!forbidden_matched && nb_vowels >= 3 && twice_in_a_row > 0) {
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
  for(int i=0; i < nb_lines; i++)
  {
    string line;
    getline(cin, line);
    if(is_nice(line)) {
      printf("%s\n", line.c_str());
      nice_lines++;
    }
  }

  cout << nice_lines << endl;

  return 0;
}

