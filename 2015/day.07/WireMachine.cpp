#include<bits/stdc++.h>

#include "WireMachine.h"

void WireMachine::AddWireNode(WireNode w) {
  this->_dict[w.Name] = w;
}

unsigned short WireMachine::QueryWireNodeValue(string name, size_t depth) {
  // std::cout << "QueryWireNodeValue('" << name << "')" << endl;
  unsigned short retVal = 0;
  
  if(_dict.find(name) == _dict.end()) {
    char buff[128];
    snprintf(buff, sizeof(buff), "QueryWireNodeValue('%s'): wire not found", name.c_str());
    std::string buffAsStdStr = buff;
    throw buffAsStdStr;
  }

  // Fisrt recursive call : initialize all cached values
  if(depth == 0) {
    for(auto& it:_dict) {
      it.second.CachedResult = -1;
    }
  }

  WireNode w = this->_dict[name];
  
  // Use the cached value if any
  if(w.CachedResult != -1)
    return (unsigned short)w.CachedResult;

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
      retVal = QueryWireNodeValue(w.Connections[0], depth+1);
      break;
    case OP_NOT:
      retVal = ~QueryWireNodeValue(w.Connections[0], depth+1);
      break;
    case OP_SHIFT_R:
      retVal = QueryWireNodeValue(w.Connections[0], depth+1) >> w.Value;
      break;
    case OP_SHIFT_L:
      retVal = QueryWireNodeValue(w.Connections[0], depth+1) << w.Value;
      break;
    case OP_AND_2_OPS:
      retVal = QueryWireNodeValue(w.Connections[0], depth+1) & QueryWireNodeValue(w.Connections[1], depth+1) ;
      break;
    case OP_AND_1_OP:
      retVal = QueryWireNodeValue(w.Connections[0], depth+1) & w.Value;
      break;
    case OP_OR_2_OPS:
      retVal = QueryWireNodeValue(w.Connections[0], depth+1) | QueryWireNodeValue(w.Connections[1], depth+1) ;
      break;
    case OP_OR_1_OP:
      retVal = QueryWireNodeValue(w.Connections[0], depth+1) | w.Value;
      break;
  }

  _dict[name].CachedResult = (int)retVal;

  return retVal;
}
