#include<bits/stdc++.h>

#include "WireMachine.h"

void WireMachine::AddWireNode(WireNode w) {
  /*
  // Check if it aready exists
  if(this->_dict.find(w.Name) != this->_dict.end()) {
    char buff[128];
    snprintf(buff, sizeof(buff), "AddWireNode(...): '%s' wire already exists", w.Name.c_str());
    std::string buffAsStdStr = buff;
    throw buffAsStdStr;
  }
  // If it references other WireNode(s), check if it(they) previously exist(s)
  int nb_refs_to_check = 0;
  switch(w.Type) {
    case IMMEDIATE:
      nb_refs_to_check = 0;
      break;
    case OP_NOT:
    case OP_SHIFTR:
    case OP_SHIFTL:
      nb_refs_to_check = 1;
      break;
    case OP_AND:
    case OP_OR:
      nb_refs_to_check = 2;
      break;
  }

  for(int i = 0; i < nb_refs_to_check; i++) {
    if(this->_dict.find(w.Connections[i]) == this->_dict.end()) {
      char buff[128];
      snprintf(buff, 
          sizeof(buff), "AddWireNode(.Name='%s'): referenced wire '%s' not found", 
          w.Name.c_str(),
          w.Connections[i].c_str());
      std::string buffAsStdStr = buff;
      throw buffAsStdStr;
    } 
  }
  */

  this->_dict[w.Name] = w;
}

unsigned short WireMachine::QueryWireNodeValue(string name) {
  unsigned short retVal = 0;
  // Check if the WireNode is immediate
  // Otherwise, recursively call this method
  if(this->_dict.find(name) == this->_dict.end()) {
    char buff[128];
    snprintf(buff, sizeof(buff), "QueryWireNodeValue('%s'): wire not found", name.c_str());
    std::string buffAsStdStr = buff;
    throw buffAsStdStr;
  }
  WireNode w = this->_dict[name];

  switch(w.Type) {
    case IDLE:
      {
        char buff[128];
        snprintf(buff, sizeof(buff), "QueryWireNodeValue('%s'): idle", w.Name.c_str());
        std::string buffAsStdStr = buff;
        throw buffAsStdStr;
      }
      break;
    case IMMEDIATE:
      retVal = w.Value; 
      break;
    case SINGLE:
      retVal = this->QueryWireNodeValue(w.Connections[0]);
      break;
    case OP_NOT:
      retVal = ~this->QueryWireNodeValue(w.Connections[0]);
      break;
    case OP_SHIFT_R:
      retVal = this->QueryWireNodeValue(w.Connections[0]) >> w.Value;
      break;
    case OP_SHIFT_L:
      retVal = this->QueryWireNodeValue(w.Connections[0]) << w.Value;
      break;
    case OP_AND_2_OPS:
      retVal = this->QueryWireNodeValue(w.Connections[0]) & this->QueryWireNodeValue(w.Connections[1]) ;
      break;
    case OP_AND_1_OP:
      retVal = this->QueryWireNodeValue(w.Connections[0]) & w.Value;
      break;
    case OP_OR_2_OPS:
      retVal = this->QueryWireNodeValue(w.Connections[0]) | this->QueryWireNodeValue(w.Connections[1]) ;
      break;
    case OP_OR_1_OP:
      retVal = this->QueryWireNodeValue(w.Connections[0]) | w.Value;
      break;
  }

  return retVal;
}
