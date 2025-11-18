#include<bits/stdc++.h>

using namespace std;

typedef struct _Reindeer {
  string Name;
  int FlySpeed;      // Speed in km/s
  int DurationSpeed; // In seconds 
  int Rest;          // In seconds
  void print();
} Reindeer;

void Reindeer::print() {
  printf("{ .Name=\"%s\", .FlySpeed=%d, .DurationSpeed=%d, .Rest=%d }",
      Name.c_str(), FlySpeed, DurationSpeed, Rest);
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

class ReindeerRace {
  private:
    vector<Reindeer> Reindeers;
    vector<int> Scores;
    vector<int> Distances;
    int RaceDuration = 0;
    bool Tick();
    int CurrentTime = 0;
  public:
    ReindeerRace(int raceDuration);
    void loadReindeer(Reindeer h);
    int getWinningReindeerScore();
    void printReindeers();
};

ReindeerRace::ReindeerRace(int raceDuration) {
  this->RaceDuration = raceDuration;
}

void ReindeerRace::printReindeers() {
  int index = 0;
  for(auto& h:Reindeers) {
    printf("[%02d]=", index++);
    h.print();
    printf("\n");
  }
}

void ReindeerRace::loadReindeer(Reindeer h) {
  Reindeers.push_back(h);
  Scores.push_back(0);
  Distances.push_back(0);
}

// Returns false if the race is finished
// Returns true if the race has still ticks to run
bool ReindeerRace::Tick() {
  CurrentTime++;

  printf("Tick #%d\n", CurrentTime);
 
  int index = 0;
  for(auto& r:Reindeers) {
    // Compute the current distance for the current Reindeer
    int cycleLength = r.DurationSpeed + r.Rest;
    int wholeCycles = CurrentTime / cycleLength;
    int distance = wholeCycles * r.FlySpeed * r.DurationSpeed;
    
    int remainder = min(CurrentTime % cycleLength, r.DurationSpeed);
    distance += remainder*r.FlySpeed;

    Distances[index] = distance;

    index++;
  }

  printf("Distances [");
  for(auto& d:Distances) {
    printf("%6d, ", d);
  }
  printf("]\n");

  int maxDistance = *max_element(Distances.begin(), Distances.end());
  printf("max distance=%d\n", maxDistance);
  vector<int> winners;
  for (int i = 0; i < (int)Distances.size(); i++) {
    if(Distances[i] == maxDistance) {
      winners.push_back(i);
      Scores[i]++;
    } 
  }

  printf("Winners   [");
  for(auto& w:winners) {
    printf("%6d, ", w);
  }
  printf("]\n");
  
  printf("Scores    [");
  for(auto& s:Scores) {
    printf("%6d, ", s);
  }
  printf("]\n");
  
  int maxScore = *max_element(Scores.begin(), Scores.end());
  printf("max score=%d\n\n", maxScore);

  bool retVal = true;
  if(CurrentTime >= RaceDuration) {
    retVal = false;
  }

  return retVal;
}

int ReindeerRace::getWinningReindeerScore() {
  int retVal = 0;
  CurrentTime = 0;
  
  while(Tick())
  {};
  
  return retVal;
}

int main (int argc, char *argv[]) {

  ReindeerRace HR(2503);

  int nb_lines;

  // Read the number of lines to read
  cin >> nb_lines;
  cin.ignore();
 
  // Process each line
  for(int i=0; i < nb_lines; i++) {
    string line;
    getline(cin, line);
    
    auto tokens = StringSplitter::split(line, string(" "), false);
    Reindeer h;
    h.Name = tokens[0];
    h.FlySpeed = stoi(tokens[3]);
    h.DurationSpeed = stoi(tokens[6]);
    h.Rest = stoi(tokens[13]);

    HR.loadReindeer(h);
  }
  
  printf("Reindeers read from input data:\n");
  HR.printReindeers();

  HR.getWinningReindeerScore();

  return 0;
}
