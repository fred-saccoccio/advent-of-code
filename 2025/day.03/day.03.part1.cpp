#include <bits/stdc++.h>

using namespace std;

int getJoltage(string s) {
  if(s.size() == 0) {
    return 0;
  }

  if(s.size() == 1) {
    return (s[0] - 0x30);
  }

  int maxJoltage = INT_MIN;
  for(size_t i = 0; i < s.size()-1; i++) {
    for(size_t j = i+1; j < s.size(); j++) {
      int joltage = (s[i]-0x30)*10 + (s[j]-0x30);
      if(joltage >= maxJoltage) {
        maxJoltage = joltage;
      }
    }
  }

  return maxJoltage;
}


int main (int argc, char *argv[]) {
  int nbLines = 0;
  cin >> nbLines;
  cin.ignore();

  int sumJoltages = 0;

  for(int i = 0; i < nbLines; i++) {
    string input;
    getline(cin, input);
    int joltage = getJoltage(input);
    printf("\tjoltage=%d\n", joltage);
    sumJoltages += joltage;
  }

  printf("%d\n", sumJoltages);

  return 0;
}
