#include<bits/stdc++.h>

using namespace std;

#include "WireMachine.h"

int main(int argc, char *argv[]) {
  try {
    WireMachine machine;

    WireNode x = { .Name="x", .Type=IMMEDIATE, .Value=123 };
    WireNode y = { .Name="y", .Type=IMMEDIATE, .Value=456 };
    
    machine.AddWireNode(x);
    machine.AddWireNode(y);
    
    short v_x = machine.QueryWireNodeValue("x");
    short v_y = machine.QueryWireNodeValue("y");

    cout << "v_x=" << v_x << ", v_y=" << v_y << endl;

    WireNode ny = { .Name="ny", .Type=OP_NOT, .Connections = {"y", ""} };
    machine.AddWireNode(ny);
    short v_ny = machine.QueryWireNodeValue("ny");
    cout << "value('ny')=" << v_ny << endl;
    
    WireNode e = { .Name="y", .Type=IMMEDIATE, .Value=456 };
    machine.AddWireNode(e);
  } catch(string err) {
    cout << "Error caught : '" << err << "'\n";
  } catch(...) {
    cout << "Error caught : ???\n";
  }
 
  return 0;
} 
