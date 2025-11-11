#include<bits/stdc++.h>

// requires at least C++11
const std::string vformat(const char * const zcFormat, ...) {

    // initialize use of the variable argument array
    va_list vaArgs;
    va_start(vaArgs, zcFormat);

    // reliably acquire the size
    // from a copy of the variable argument array
    // and a functionally reliable call to mock the formatting
    va_list vaArgsCopy;
    va_copy(vaArgsCopy, vaArgs);
    const int iLen = std::vsnprintf(NULL, 0, zcFormat, vaArgsCopy);
    va_end(vaArgsCopy);

    // return a formatted string without risking memory mismanagement
    // and without assuming any compiler or platform specific behavior
    std::vector<char> zc(iLen + 1);
    std::vsnprintf(zc.data(), zc.size(), zcFormat, vaArgs);
    va_end(vaArgs);
    return std::string(zc.data(), iLen); 
}

void help() {
  std::cout << "syntax : look-and-say.exe <string_to_process>" << std::endl;
}

std::string look_and_say(std::string data) {
  char previous_char = '#';
  char current_char;
  int index = 0;
  int N = data.size();
  std::string buffer = "";
  std::string ret_val = "";
  
  while(index < N) {
    current_char = data[index];
    
    if(current_char != previous_char) {
      if(buffer.size() > 0) {
        int s = buffer.size();
        std::string to_append = vformat("%d%c", s, buffer[0]);
        ret_val += to_append;
      }
      buffer.clear();
      buffer.append(std::string(1, current_char));
    } else {
       buffer.append(std::string(1, current_char));
    }

    previous_char = current_char;
    index++;
  }

  if(buffer.size() > 0) {
    int s = buffer.size();
    std::string to_append = vformat("%d%c", s, buffer[0]);
    ret_val += to_append;
  }
  
  return ret_val; 
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cout << "Not enough arguments on the cmd line." << std::endl;
    help();
    return 1;
  } 
  // std::printf("arg = %s\n", argv[1]);
  std::string input(argv[1]);

  int iterations = stoi(std::string(argv[2]));

  for(int iteration = 1; iteration <= iterations; iteration++) {
    input = look_and_say(input);
  }
  std::cout << input << "\n";
  std::cout << "length=" << input.size() << "\n";
  
  return 0;
}
