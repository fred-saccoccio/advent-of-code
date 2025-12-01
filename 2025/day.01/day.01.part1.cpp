#include <bits/stdc++.h>

using namespace std;
  
int safe_modulo(int n, int modulus) {
  return ((n % modulus) + modulus) % modulus;
}

const int MAX_CLICKS = 100;

int main (int argc, char *argv[]) {
  int nb_lines = 0;

  int start = 50;

  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();

  int point_at_zero = 0;
 
  // Process each line
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);
    char direction = 0;
    int rotation = 0;
    int multiplier = 1;
    sscanf(line.c_str(), "%c%d", &direction, &rotation);
    if(direction == 'R') {
      multiplier = 1;
    } else if(direction == 'L') {
      multiplier = -1;
    }
    start = safe_modulo(start + multiplier*rotation, MAX_CLICKS);
    if(start == 0) {
      point_at_zero++;
    }
  }

  printf("%d\n", point_at_zero);

  return 0;
}
