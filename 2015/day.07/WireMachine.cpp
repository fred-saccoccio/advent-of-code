#include<bits/stdc++.h>

using namespace std;

#include "WireMachine.h"

void WireMachine::AddWireNode(WireNode w) {
  // Try to add the node in the internal dictionnary
  if(this->_Dictionnary.find(w.Name) != this->_Dictionnary.end()) {
    throw "Error already exist";
  }
  
  this->_Dictionnary[w.Name] = w;

  // Check if it aready exists
  // If it references other WireNodes, check if they previously exist
}

short WireMachine::QueryWireNodeValue(string name) {
  short retVal = 0;
  // Check if the WireNode is immediate
  // Otherwise, recursively call this method
  if(this->_Dictionnary.find(name) == this->_Dictionnary.end()) {
    char buff[128];
    snprintf(buff, sizeof(buff), "QueryWireNodeValue('%s'): wire not found", name.c_str());
    std::string buffAsStdStr = buff;
    throw buffAsStdStr;
  }
  WireNode w = this->_Dictionnary[name];

  switch(w.Type) {
    case IMMEDIATE:
      retVal = w.Value; 
      break;
    case OP_NOT:
      retVal = ~this->QueryWireNodeValue(w.Connections[0]);
      break;
    case OP_SHIFTR:
      retVal = this->QueryWireNodeValue(w.Connections[0]) >> w.Shift;
      break;
    case OP_SHIFTL:
      retVal = this->QueryWireNodeValue(w.Connections[0]) << w.Shift;
      break;
    case OP_AND:
      retVal = this->QueryWireNodeValue(w.Connections[0]) & this->QueryWireNodeValue(w.Connections[1]) ;
      break;
    case OP_OR:
      retVal = this->QueryWireNodeValue(w.Connections[0]) | this->QueryWireNodeValue(w.Connections[1]) ;
      break;
  }

  return retVal;
}
