#include <bits/stdc++.h>

using namespace std;

class Pwd{
public:
  Pwd();
  Pwd(Pwd &&) = default;
  Pwd(const Pwd &) = default;
  Pwd &operator=(Pwd &&) = default;
  Pwd &operator=(const Pwd &) = default;
  ~Pwd();
  void setBuffer(string s);
  string getBuffer();
  void incBuffer();
  bool isValid();

private:
  string buffer;
  char incChar(char c, bool &carry);
  string incString(string s);
};

Pwd::Pwd() {
}

Pwd::~Pwd() {
}

bool Pwd::isValid() {

  // Search forbidden letters : o, i and l
  for(auto c:buffer) {
    if(c == 'i' || c == 'o' || c == 'l') {
      return false;
    }
  }

  // Check for increasing group of 3
  bool incGroupOfThree = false;
  int N = buffer.size();

  for(int index = 0; index < N-2; index++) {
    if(buffer[index+1] == buffer[index]+1 && buffer[index+2] == buffer[index+1]+1) {
      incGroupOfThree = true;
      break;
    }
  }

  // Check for at least two different, non-overlapping pairs of letters, like aa, bb, or zz
  bool atLeastTwoDifferent = false;
  
  // For each possible group of 2
  for(int index = 0; index < N-1; index++) {
    // Check if we have a group of 2 equal letters
    if(buffer[index] != buffer[index+1]) {
      continue;
    }
    
    // Look at the left of the current group
    for(int k = 0; k < index-2; k++) {
      if(buffer[k] == buffer[k+1]) {
        atLeastTwoDifferent = true;
        break;
      }
    }

    if(atLeastTwoDifferent == true)
      break;

    // Look at the right of the current group
    for (int k = index+2; k < N-1; k++) {
      if(buffer[k] == buffer[k+1]) {
        atLeastTwoDifferent = true;
        break;
      }
    }
    
    if(atLeastTwoDifferent == true)
      break;
  }

  return (incGroupOfThree && atLeastTwoDifferent);
}

char Pwd::incChar(char c, bool &carry) {
  char retVal = '#';
  if('a' <= c && c <= 'y') {
    retVal = c + 1;
    carry = false;
  } else if(c == 'z') {
    retVal = 'a';
    carry = true;
  }
  return retVal;
}

void Pwd::setBuffer(string s) {
  buffer = s;
}

string Pwd::getBuffer() {
  return buffer;
}

void Pwd::incBuffer() {
  bool carry = true;
  int N = buffer.size();
  int i = N-1;
  while(carry == true && i >= 0) {
    char c = incChar(buffer[i], carry);
    buffer[i] = c;
    i--;
  }
}

int main() {
  Pwd pwd;
  pwd.setBuffer("hxbxwxba");
  size_t iteration = 0;
  while(! pwd.isValid()) {
    pwd.incBuffer();
    iteration++;
  }

  printf("#iteration %zu, new password=%s\n", iteration, pwd.getBuffer().c_str());

  return 0;
}

