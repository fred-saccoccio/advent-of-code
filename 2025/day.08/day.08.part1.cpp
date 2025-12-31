#include <bits/stdc++.h>
using namespace std;
#define VERBOSE
struct Point3d {
  int X;
  int Y;
  int Z;
  int Circuit;

  void print() {
    printf("{X=%8d,Y=%8d,Z=%9d,Circuit=%4d}", X, Y, Z, Circuit);
  }

  void println() {
    print();
    printf("\n");
  }
};

struct JunctionBoxesDist {
  size_t Line;
  size_t Col;
  double Dist;
  
  bool operator<(const JunctionBoxesDist& other) const {
    return Dist < other.Dist;
  }

  void print() {
    printf("{Line=%4lu,Col=%4lu,Dist=%8.2f}", Line, Col, Dist);
  }

  void println() {
    print();
    printf("\n");
  }
};

double distance(Point3d p, Point3d q) {
  return sqrt((q.X-p.X)*(q.X-p.X) + (q.Y-p.Y)*(q.Y-p.Y) + (q.Z-p.Z)*(q.Z-p.Z));
}

void print_distances(double **d, size_t s) {
  for(size_t i = 0; i < s; i++) {
    printf("%8zu", i);
    if(i < s-1)
      printf(" ");
  }
  printf("\n");
  
  for(size_t i = 0; i < s; i++) {
    printf("--------");
    if(i < s-1)
      printf("-");
  }
  printf("\n");

  for(size_t line = 0; line < s; line++) {
    for(size_t col = 0; col < s; col++) {
      printf("%8.2f", d[line][col]);
      if(col < s-1)
        printf(" ");
    }
    printf("\n");
  }
}

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

const size_t MAX_SIZE=1000;

int main (int argc, char *argv[]) {
  double** distances;
  distances = new double*[MAX_SIZE];
  for(size_t i = 0; i < MAX_SIZE; i++) {
    distances[i] = new double[MAX_SIZE];
  }
  Point3d* boxes = new Point3d[MAX_SIZE];

  // Read input data
  string input;
  size_t line_index = 0;
  size_t lines = 0;
  while(getline(cin, input)) {
    // Split the line with coma as separator
    auto splits = StringSplitter::split(input, ",");
    int x = stoi(splits[0]);
    int y = stoi(splits[1]);
    int z = stoi(splits[2]);

    boxes[line_index].X = x;
    boxes[line_index].Y = y;
    boxes[line_index].Z = z;
    boxes[line_index].Circuit = line_index;

    if(line_index >= MAX_SIZE-1)
      break;

    line_index++;
  }

  lines = line_index;

  for(size_t i = 0; i < lines; i++) {
    printf("[%4zu]=", i);
    boxes[i].println();
  }

  vector<JunctionBoxesDist> dists;
  double min_distance = DBL_MAX;
  size_t line_min, col_min;
  for(size_t line = 0; line < lines; line++) {
    for(size_t col = line+1; col < lines; col++) {
      double val = distance(boxes[line], boxes[col]);
      distances[line][col] = val;
      JunctionBoxesDist jb;
      jb.Line = line;
      jb.Col = col;
      jb.Dist = val;
      dists.push_back(jb);
      if(val < min_distance) {
        min_distance = val;
        line_min = line;
        col_min = col;
      }
    }
  }

  sort(dists.begin(), dists.end());

  print_distances(distances, lines);

  printf("min=%f (%zu,%zu)\n", min_distance, line_min, col_min);

  size_t iteration = 0;
  size_t MAX_ITERATIONS = 10;
  for(auto d:dists) {
    iteration++;
    int m = min(boxes[d.Line].Circuit, boxes[d.Col].Circuit);
    int M = max(boxes[d.Line].Circuit, boxes[d.Col].Circuit);
    for(size_t index = 0; index < lines; index++) {
      if(boxes[index].Circuit == M)
        boxes[index].Circuit = m;
    }
#ifdef VERBOSE
    printf("iteration=%lu\n", iteration);
    d.println();
    for(size_t i = 0; i < lines; i++) {
      printf("[%4zu]=", i);
      boxes[i].println();
    }
    char ans;
    cin >> ans;
#endif
    if(iteration >= MAX_ITERATIONS)
      break;
  }

  unordered_map<int,int> results;
  for(size_t i = 0; i < lines; i++) {
    if(results.find(boxes[i].Circuit) != results.end()) {
      results[boxes[i].Circuit]++;
    } else {
      results[boxes[i].Circuit] = 1;
    }
  }
  
  vector<int> sorted_results;
  for(const auto& res:results) {
    sorted_results.push_back(res.second);
  }

  sort(sorted_results.begin(), sorted_results.end(), std::greater<int>());

  int result = sorted_results[0] * sorted_results[1] * sorted_results[2];

  printf("result=%d\n", result);

  for(size_t i = 0; i < lines; i++) {
    printf("[%4zu]=", i);
    boxes[i].println();
  }
  
  delete [] boxes;
  for(size_t i = 0; i < MAX_SIZE; i++) {
    delete [] distances[i];
  }
  delete [] distances;
}

