#include <bits/stdc++.h>
using namespace std;

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
  unsigned long long int Dist;
  
  bool operator<(const JunctionBoxesDist& other) const {
    return Dist < other.Dist;
  }

  void print() {
    printf("{Line=%4lu,Col=%4lu,Dist=%llu}", Line, Col, Dist);
  }

  void println() {
    print();
    printf("\n");
  }
};

unsigned long long int distance_sqr(Point3d p, Point3d q) {
  long long dx = (long long)q.X - p.X;
  long long dy = (long long)q.Y - p.Y;
  long long dz = (long long)q.Z - p.Z;
  return dx*dx + dy*dy + dz*dz;
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
  size_t MAX_ITERATIONS = 0;
  bool first_line = true;
  while(getline(cin, input)) {
    // The 1st line is the maximum iterations number
    if(first_line) {
      MAX_ITERATIONS = stoi(input);
      first_line = false;
      continue;
    }
    // Split the line with coma as separator
    auto splits = StringSplitter::split(input, ",");
    int x = stoi(splits[0]);
    int y = stoi(splits[1]);
    int z = stoi(splits[2]);

    boxes[line_index].X = x;
    boxes[line_index].Y = y;
    boxes[line_index].Z = z;
    boxes[line_index].Circuit = line_index;

    line_index++;
  }

  lines = line_index;

#ifdef VERBOSE
  for(size_t i = 0; i < lines; i++) {
    printf("[%4zu]=", i);
    boxes[i].println();
  }
#endif

  vector<JunctionBoxesDist> dists;
  for(size_t line = 0; line < lines; line++) {
    for(size_t col = line+1; col < lines; col++) {
      unsigned long long int val = distance_sqr(boxes[line], boxes[col]);
      distances[line][col] = val;
      JunctionBoxesDist jb;
      jb.Line = line;
      jb.Col = col;
      jb.Dist = val;
      dists.push_back(jb);
    }
  }

  sort(dists.begin(), dists.end());

  size_t iteration = 0;
  for(auto d:dists) {
    //if(iteration == MAX_ITERATIONS)
    //  break;

    // iteration++;

    int c1 = boxes[d.Line].Circuit;
    int c2 = boxes[d.Col].Circuit;
    if(c1 != c2) {
      int m = min(c1,c2);
      int M = max(c1,c2);
      for(size_t index = 0; index < lines; index++) {
        if(boxes[index].Circuit == M)
          boxes[index].Circuit = m;
      }
      
      // Check for single circuit
      int ref = boxes[0].Circuit;
      bool singleCircuit = true;
      for(size_t index = 0; index < lines; index++) {
        if(boxes[index].Circuit != ref) {
          singleCircuit = false;
          break;
        }
      }
      if(singleCircuit) {
        unsigned long long int lX = (unsigned long long int)boxes[d.Line].X;
        unsigned long long int lY = (unsigned long long int)boxes[d.Col].X;
        unsigned long long int lRes = lX*lY;
        printf("result=%llu\n", lRes);
        break;
      }
    }
    
#ifdef VERBOSE
    printf("iteration=%lu\n", iteration);
    d.println();
    for(size_t i = 0; i < lines; i++) {
      printf("[%4zu]=", i);
      boxes[i].println();
    }
#endif
    if(iteration > MAX_ITERATIONS)
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

#ifdef VERBOSE
  for(size_t i = 0; i < lines; i++) {
    printf("[%4zu]=", i);
    boxes[i].println();
  }
#endif

  vector<int> sorted_results;
  for(const auto& res:results) {
    sorted_results.push_back(res.second);
  }

  sort(sorted_results.begin(), sorted_results.end(), std::greater<int>());

  int result = sorted_results[0] * sorted_results[1] * sorted_results[2];

  // printf("result=%d\n", result);
  
  delete [] boxes;
  for(size_t i = 0; i < MAX_SIZE; i++) {
    delete [] distances[i];
  }
  delete [] distances;
}

