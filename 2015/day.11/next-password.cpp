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

private:
  string buffer;
  char incChar(char c, bool &carry);
  string incString(string s);
};

Pwd::Pwd() {
}

Pwd::~Pwd() {
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
  for(int index = 0; index < 10000; index++) {
    printf("[%05d]=%s\n", index, pwd.getBuffer().c_str());
    pwd.incBuffer();
  }

  return 0;
}

