#include<bits/stdc++.h>

using namespace std;

#include "WireMachine.h"

void split(const std::string& str, std::vector<std::string>& v) {
  std::stringstream ss(str);
  ss >> std::noskipws;
  std::string field;
  char ws_delim;
  while(1) {
    if( ss >> field )
      v.push_back(field);
    else if (ss.eof())
      break;
    else
      v.push_back(std::string());
    ss.clear();
    ss >> ws_delim;
  }
}

void interactiveMode(WireMachine &m) {
  cout << "Interactive mode (type QUIT to exit)\n";
  string cmd = "";
  do {
    getline(cin, cmd);
    std::vector<std::string> tokens;
    split(cmd, tokens);
    if(tokens.size() >= 2 && tokens[0] == "QUERY") {
      try {
        unsigned short v = m.QueryWireNodeValue(tokens[1]);
        cout << tokens[1] << "=" << v << endl;
      } catch(string exc) {
        cout << "Error when querying '" << tokens[1] << "' value: " << exc << endl; 
      }
    } 
  } while(cmd != "QUIT");
}



// 36 -> a
// QUERY a
void testImmediate() {
  WireMachine machine;
  WireNode n = {.Name="aa", .Type=IMMEDIATE, .Value=36};
  machine.AddWireNode(n);
  unsigned short v = machine.QueryWireNodeValue("aa");
  assert((v == 36));
}

// aa
// QUERY aa
// 812 -> aa
// query aa
void testUpdateWireNode() {
  WireMachine machine;
  WireNode n = {.Name="aa", .Type=IDLE };
  machine.AddWireNode(n);
  
  bool exception_caught = false;
  unsigned short v = 0;
  try {
    v = machine.QueryWireNodeValue("aa");
  } catch(string &err) {
    exception_caught = true;
  }

  assert((exception_caught == true));
  n.Type = IMMEDIATE;
  n.Value = 812;

  try {
    v = machine.QueryWireNodeValue("aa");
  } catch(string &err) {
    exception_caught = true;
    cout << err << endl;
  }
  machine.AddWireNode(n);
  v = machine.QueryWireNodeValue("aa");
  assert((v == 812));
}

// NOT a -> b
// QUERY a
// QUERY b
// 12 -> a
// QUERY a
// QUERY b
void testImmediateOp() {
  WireMachine machine;
  // NOT a -> b
  WireNode b = { .Name="b", .Type=OP_NOT, .Connections={"a",""} };
  machine.AddWireNode(b);
  
  // QUERY a
  unsigned short v = 0;
  bool exception_caught = false; 
  try {
    v = machine.QueryWireNodeValue("a");
  } catch(string &err) {
    exception_caught = true;
    cout << err << endl;
  }
  assert((exception_caught == true));
  
  // QUERY b
  exception_caught = false; 
  try {
    v = machine.QueryWireNodeValue("b");
  } catch(string &err) {
    exception_caught = true;
    cout << err << endl;
  }
  assert((exception_caught == true));

  WireNode a = { .Name="a", .Type=IMMEDIATE, .Value=12 };
  machine.AddWireNode(a);
  
  v = machine.QueryWireNodeValue("a");
  assert((v == 12));
  v = machine.QueryWireNodeValue("b");
  assert((v == 65523));
}

// 123 -> x
// 456 -> y
// x AND y -> d
// x OR y -> e
// x LSHIFT 2 -> f
// y RSHIFT 2 -> g
// NOT x -> h
// NOT y -> i
void testSampleAoC() {
  WireMachine machine;
  // 123 -> x 
  WireNode x = { .Name="x", .Type=IMMEDIATE, .Value=123 };
  machine.AddWireNode(x);

  // 456 -> y
  WireNode y = { .Name="y", .Type=IMMEDIATE, .Value=456 };
  machine.AddWireNode(y);

  // x AND y -> d
  WireNode d = { .Name="d", .Type=OP_AND_2_OPS, .Value=0, .Connections={"x", "y"} };
  machine.AddWireNode(d);

  // x LSHIFT 2 -> f
  WireNode f = { .Name="f", .Type=OP_SHIFT_L, .Value=2, .Connections={"x", ""} };
  machine.AddWireNode(f);

  // y RSHIFT 2 -> g
  WireNode g = { .Name="g", .Type=OP_SHIFT_R, .Value=2, .Connections={"y", ""} };
  machine.AddWireNode(g);
  
  // NOT x -> h
  WireNode h = { .Name="h", .Type=OP_NOT, .Value=0, .Connections={"x", ""} };
  machine.AddWireNode(h);
  
  // NOT y -> i
  WireNode i = { .Name="i", .Type=OP_NOT, .Value=0,  .Connections={"y", ""} };
  machine.AddWireNode(i);

  // x OR y -> e
  WireNode e = { .Name="e", .Type=OP_OR_2_OPS, .Value=0, .Connections={"x", "y"} };
  machine.AddWireNode(e);

  // aa -> bb
  WireNode bb = { .Name="bb", .Type=SINGLE, .Value=0, .Connections={"aa", ""} };
  machine.AddWireNode(bb);

  interactiveMode(machine);

  vector<string> wires = { "d", "e", "f", "g", "h", "i", "x", "y"};

  for(string s : wires) {
    unsigned short val = machine.QueryWireNodeValue(s);
    cout << s << "=" << val << endl;
  }
}

int main(int argc, char *argv[]) {

  testImmediate();
  testUpdateWireNode();
  testImmediateOp();
  testSampleAoC();

  WireMachine machine;
  
  WireNode buffer;
  // NOT d -> e
  WireNode d = { .Name="d", .Type=IDLE };
  machine.AddWireNode(d);
  
  WireNode e = { .Name="e", .Type=OP_NOT, .Connections={"d",""} };
  machine.AddWireNode(e);
  
  // b -> c
  WireNode b = { .Name="b", .Type=IDLE };
  machine.AddWireNode(b);
  
  WireNode c = { .Name="c", .Type=SINGLE, .Connections={"b",""} };
  machine.AddWireNode(c);
  
  // a -> b
  WireNode a = { .Name="a", .Type=IDLE };
  machine.AddWireNode(a);
  
  buffer.Name = "b";
  buffer.Type = SINGLE;
  buffer.Connections[0] = "a";
  buffer.Connections[1] = "";
  machine.AddWireNode(buffer);
  
  // c -> d
  buffer.Name = "d";
  buffer.Type = SINGLE;
  buffer.Connections[0] = "c";
  buffer.Connections[1] = "";
  machine.AddWireNode(buffer);
  
  // 12 -> a
  buffer.Name = "a";
  buffer.Type = IMMEDIATE;
  buffer.Connections[0] = "";
  buffer.Connections[1] = "";
  buffer.Value = 12;
  machine.AddWireNode(buffer);

  unsigned short v_e = machine.QueryWireNodeValue("e");
  cout << "e=" << v_e << endl;

  WireNode x = { .Name="x", .Type=IDLE };
  WireNode y = { .Name="y", .Type=IMMEDIATE, .Value=456 };
  
  machine.AddWireNode(x);
  machine.AddWireNode(y);
  
  unsigned short v_x = 0; 
  
  try {
    v_x = machine.QueryWireNodeValue("x");
  } catch(string err) {
    cout << "Error caught : '" << err << "'\n";
  } catch(...) {
    cout << "Error caught : ???\n";
  }

  WireNode n_x = { .Name="nx", .Type=OP_NOT, .Connections={"x", ""} };
  machine.AddWireNode(n_x);
  unsigned short v_nx= 0;
  try {
    v_nx = machine.QueryWireNodeValue("nx");
  } catch(string err) {
    cout << "Error caught : '" << err << "'\n";
  } catch(...) {
    cout << "Error caught : ???\n";
  }

  
  try {

    unsigned short v_y = machine.QueryWireNodeValue("y");

    cout << "v_x=" << v_x << ", v_y=" << v_y << endl;

    x.Type=IMMEDIATE;
    x.Value=123;
    machine.AddWireNode(x);
    v_x = machine.QueryWireNodeValue("x");
    cout << "v_x=" << v_x << ", v_y=" << v_y << endl;


    unsigned short v_nx = machine.QueryWireNodeValue("nx");
    cout << "v_nx=" << v_nx << endl;

    
    WireNode ny = { .Name="ny", .Type=OP_NOT, .Connections = {"y", ""} };
    machine.AddWireNode(ny);
    unsigned short v_ny = machine.QueryWireNodeValue("ny");
    cout << "value('ny')=" << v_ny << endl;
    
    WireNode e = { .Name="y", .Type=IMMEDIATE, .Value=1 };
    machine.AddWireNode(e);

    v_ny = machine.QueryWireNodeValue("ny");
    cout << "value('ny')=" << v_ny << endl;

  } catch(string err) {
    cout << "Error caught : '" << err << "'\n";
  } catch(...) {
    cout << "Error caught : ???\n";
  }
 
  return 0;
} 
