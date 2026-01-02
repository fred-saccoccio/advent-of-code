#include <bits/stdc++.h>
using namespace std;

class StringSplitter {
  public:
    static std::vector<std::string> split(const std::string& str,
        const std::string& delimiters,
        bool keepEmpty = false) {
      std::vector<std::string> tokens;
      std::string::size_type pos = 0;
      std::string::size_type prev = 0;
      
      while ((pos = str.find_first_of(delimiters, prev)) != std::string::npos) {
        if (keepEmpty || pos > prev) {
          tokens.push_back(str.substr(prev, pos - prev));
        }
        prev = pos + 1;
      }
      
      if (prev < str.length()) {
        tokens.push_back(str.substr(prev));
      } else if (keepEmpty && prev == str.length()) {
        tokens.push_back("");
      }
      
      return tokens;
    }
};

const size_t MAX_POINTS = 500;

struct Point2d {
  int X;
  int Y;
};

int main (int argc, char *argv[]) {
  Point2d *points;
  points = new Point2d[MAX_POINTS];
  // Read input data
  string input;
  size_t line_index = 0;
  size_t lines = 0;
  while(getline(cin, input)) {
    auto splits = StringSplitter::split(input, ",");
    points[line_index].X = stoi(splits[0]);
    points[line_index].Y = stoi(splits[1]);
    line_index++;
  }

  lines = line_index;
  long long int max_surface = 0;
  for(size_t i = 0; i < lines-1; i++) {
    for(size_t j = i+1; j < lines; j++) {
      // printf("{%zu,%zu}\n", i, j);
      int min_X = min(points[i].X, points[j].X);
      int max_X = max(points[i].X, points[j].X);
      int min_Y = min(points[i].Y, points[j].Y);
      int max_Y = max(points[i].Y, points[j].Y);
      long long int dx = (long long int)max_X - min_X + 1;
      long long int dy = (long long int)max_Y - min_Y + 1;
      long long int surface = dx * dy;
      if(surface > max_surface)
        max_surface = surface;
    }
  }

  printf("%llu\n",max_surface);

  delete [] points;

  return 0;
}
