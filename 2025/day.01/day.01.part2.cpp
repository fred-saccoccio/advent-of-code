#include <bits/stdc++.h>

using namespace std;
  
int safe_modulo(int n, int modulus) {
  return ((n % modulus) + modulus) % modulus;
}

const int MAX_CLICKS = 100;

int main (int argc, char *argv[]) {
  int nb_lines = 0;

  int start = 50;

  // Read the start position
  cin >> start;

  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();

  int zero_traversals = 0;

  printf("start=%d\n", start);
 
  // Process each line
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);
    char direction = 0;
    int rotation = 0;
    int multiplier = 1;

    printf("%s->",line.c_str());

    sscanf(line.c_str(), "%c%d", &direction, &rotation);
    
    if(direction == 'R') {
      multiplier = 1;
    } else if(direction == 'L') {
      multiplier = -1;
    }
    int prev_start = start;
    start = safe_modulo(start + multiplier*rotation, MAX_CLICKS);
    printf("start=%d", start);
    
    int remainder = 0;
    if(multiplier > 0) {
      zero_traversals += (rotation / MAX_CLICKS);
      remainder = (prev_start + (rotation % MAX_CLICKS)) >= MAX_CLICKS ? 1 : 0;
      zero_traversals += remainder;
    } else {
      // multiplier < 1
      zero_traversals += (rotation / MAX_CLICKS);
      remainder = (prev_start != 0) && ( (prev_start - (rotation % MAX_CLICKS)) <= 0) ? 1 : 0;
      zero_traversals += remainder;
    }

    printf("(zero traversals=%d)\n", zero_traversals);
    
  }

  printf("%d\n", zero_traversals);

  return 0;
}
