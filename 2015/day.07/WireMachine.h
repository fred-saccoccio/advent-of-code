#ifndef __DAY_07_H__
#define __DAY_07_H__
#include<unordered_map>
#include<string>
using namespace std;

enum TypeEnum {
  IDLE,         // The wire is not connected to anything:
                // => it can't deliver a level
  IMMEDIATE,    // The wire has its own level:
                //   .Value : stores this level
  SINGLE,       // The wire is directlty connected to another wire
                // => it has the level of this connected wire :
                //   .Connections[0] stores the name of the connected wire
  OP_NOT,       // The wire is connected to another one through a NOT gate:   
                //   .Connections[0] stores the name of the connected wire
  OP_SHIFT_R,   // The wire is connected to another one through a SHIFT_RIGHT gate
                //   .Connections[0] stores the name of the connected wire
                //   .Value stores the value for computing the shift
  OP_SHIFT_L,   // The wire is connected to another one through a SHIFT_LEFT gate
                //   .Connections[0] stores the name of the connected wire
                //   .Value stores the value for computing the shift
  OP_AND_2_OPS, // The wire is connected to 2 other wires through an AND gate
                //   .Connections[0] and .Connections[1] store the names of the connected wires
  OP_AND_1_OP,  // The wire is connected to 1 wire and an immediate value through an AND gate
                //   .Connections[0] stores the name of the connected wire
                //   .Value stores the value for computing the AND 
  OP_OR_2_OPS,  // The wire is connected to 2 other wires through an OR gate
                //   .Connections[0] and .Connections[1] store the names of the connected wires
  OP_OR_1_OP    // The wire is connected to 2 other wires through an OR gate
                //   .Connections[0] stores the name of the connected wire
                //   .Value stores the value for computing the OR 
};



typedef struct _WireNode {
  string Name;
  TypeEnum Type; 
  unsigned short Value;
  int CachedResult;
  string Connections[2];
  void print() { 
    cout << "{ .Name='" << Name 
      << "', .Type=" << typeToStr(Type) 
      << ", .Value=" << Value 
      << ", .Connections={'" << Connections[0] << "','" << Connections[1] << "'} }"
      << endl;
  }
  
  private:
  std::string typeToStr(TypeEnum t) {
    switch(t) {
      case IDLE:
        return std::string("IDLE");
        break;
      case IMMEDIATE:
        return std::string("IMMEDIATE");
        break;
      case SINGLE:
        return std::string("SINGLE");
        break;
      case OP_NOT:
        return std::string("OP_NOT");
        break;
      case OP_SHIFT_R:
        return std::string("OP_SHIFT_R");
        break;
      case OP_SHIFT_L:
        return std::string("OP_SHIFT_L");
        break;
      case OP_AND_2_OPS:
        return std::string("OP_AND_2_OPS");
        break;
      case OP_AND_1_OP:
        return std::string("OP_AND_1_OP");
        break;
      case OP_OR_2_OPS:
        return std::string("OP_OR_2_OPS");
        break;
      case OP_OR_1_OP:
        return std::string("OP_OR_1_O");
        break;
      default:
        return std::string("UNKNOWN");
    }
  }
} WireNode;  

class WireMachine {
  private:
    unordered_map<string, WireNode> _dict;
  public:
    void AddWireNode(WireNode w);
    unsigned short QueryWireNodeValue(string name, size_t depth);
};
#endif

