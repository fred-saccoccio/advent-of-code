#include<bits/stdc++.h>

using namespace std;

typedef struct _string_measures {
  size_t initial_length;
  size_t encoded_length;
  void print() {
    cout << "{ .initial_length=" << initial_length << ", .encoded_length=" << encoded_length << " }" << endl;
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

  // Set s_m.initial_length
  s_m.initial_length = trimmed_s.size();
  cout << "Initial=|" << trimmed_s << "| ";

  regex dquote(R"(")");
  regex backslash(R"(\\)");

  // Escape backslashes
  string encoded = regex_replace(trimmed_s, backslash, R"(\\)"); 
  // Escape double quotes 
  encoded = regex_replace(encoded, dquote, R"(\")");
  encoded = string("\"") + encoded + string("\"");
  
  cout << "Encoded=|" << encoded << "|" << endl;

  s_m.encoded_length = encoded.size();
  
  return ret_val;
}

int main()
{
  int nb_lines;
  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();

  size_t total_initial_length = 0;
  size_t total_encoded_length = 0;
    
  // Process each line
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);
    string_measure measure;
    if(measure_string(line, measure)) {
      measure.print();
      total_initial_length += measure.initial_length;
      total_encoded_length += measure.encoded_length;
    } else {
      cout << "Invalid input" << endl;
    }
  }

  cout << "Total encoded length=" << total_encoded_length << endl;
  cout << "Total initial length=" << total_initial_length << endl;
  cout << "Delta=" << total_encoded_length - total_initial_length << endl;
}

