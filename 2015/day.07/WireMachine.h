#ifndef __DAY_07_H__
#define __DAY_07_H__

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
  string Connections[2];
} WireNode; 

class WireMachine {
  private:
    map<string, WireNode> _dict;
  public:
    void AddWireNode(WireNode w);
    unsigned short QueryWireNodeValue(string name);
};
#endif

