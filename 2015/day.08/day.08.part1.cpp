#include<bits/stdc++.h>

using namespace std;

typedef struct _string_measures {
  size_t length;
  size_t memory;
  void print() {
    cout << "{ .length=" << length << ", .memory=" << memory << " }" << endl;
  }
} string_measure; 

std::string trim(const std::string & source) {
  std::string s(source);
  
  s.erase(0,s.find_first_not_of(" \n\r\t"));
  s.erase(s.find_last_not_of(" \n\r\t")+1);

  return s;
}

bool measure_string(string s, string_measure& s_m) {
  bool ret_val = false;
  
  std::string trimmed_s = trim(s);
  regex correct_string(R"(^\".*\"$)");

  // Check if input is a valid string
  if(regex_match(trimmed_s, correct_string)) {
    ret_val = true;
  } else {
    return false;
  }

  // Set s_m.length
  s_m.length = trimmed_s.size();

  trimmed_s = trimmed_s.substr(1, trimmed_s.size()-2);
  
  regex escape_dquote(R"(\\")");
  regex escape_backslash(R"(\\\\)");
  regex escape_hex(R"(\\x[0-9a-fA-F]{2})");
  
  string buffer = regex_replace(trimmed_s, escape_dquote, "|");
  buffer = regex_replace(buffer, escape_backslash, "%");
  buffer = regex_replace(buffer, escape_hex, "*");

  cout << "buffer=|" << buffer << "|" << endl;

  s_m.memory = buffer.size();
  
  return ret_val;
}

int main()
{
  int nb_lines;
  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();

  size_t total_length = 0;
  size_t total_memory= 0;
    
  // Process each line
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);
    string_measure measure;
    if(measure_string(line, measure)) {
      measure.print();
      total_length += measure.length;
      total_memory += measure.memory;
    } else {
      cout << "Invalid input" << endl;
    }
  }

  cout << "Total length=" << total_length << endl;
  cout << "Total memory=" << total_memory << endl;
  cout << "Delta=" << total_length - total_memory << endl;
}

