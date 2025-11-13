#include <iostream>
#include <iomanip>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

long long int evalJson(json& d) {
  if(d.is_number_integer()) {
    return d.get<int>();
  } else if(d.is_structured()) {
     long long int retVal = 0;
     for(auto& n:d) {
       retVal += evalJson(n);
     }
     return retVal;
  } else {
    return 0;
  }
}

int main (int argc, char *argv[]) {
  if(argc < 2) {
    std::printf("Error: please specify the path of the file to process on the command line.\n");
    std::printf("Syntax: %s [file_to_process]\n", argv[0]);
    return 1;
  }
  std::fstream File;
  File.open(argv[1], std::ios::in);
  json Doc{json::parse(File)};
    
  long long int val = evalJson(Doc);

  std::cout << val << "\n";
 
  return 0;
}

