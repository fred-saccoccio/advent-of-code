#ifndef __DAY_07_H__
#define __DAY_07_H__

enum TypeEnum {IMMEDIATE, OP_NOT, OP_SHIFTR, OP_SHIFTL, OP_AND, OP_OR};
typedef struct _WireNode {
  string Name;
  TypeEnum Type; 
  short Value;
  string Connections[2];
  int Shift;
} WireNode; 

class WireMachine {
  private:
    map<string, WireNode> _Dictionnary;
  public:
    void AddWireNode(WireNode w);
    short QueryWireNodeValue(string name);
};
#endif

