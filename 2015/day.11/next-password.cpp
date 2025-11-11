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
  string getNextPwd();

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

string Pwd::getNextPwd() {
  string retVal;
  bool carry = false;
  char c = incChar(buffer[7], carry);
  cout << c << endl;
  return retVal;
}

int main() {
  Pwd pwd;
  pwd.setBuffer("hxbxwxba");
  pwd.getNextPwd();

  return 0;
}
