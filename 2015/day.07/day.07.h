#ifndef __DAY_07_H__
#define __DAY_07_H__
enum TypeEnum {IMMEDIATE, OP_NOT, OP_SHIFTR, OP_SHIFTL, OP_AND, OP_OR};
typedef struct _WireNode {
  string Name;
  TypeEnum Type; 
  short value;
  string Connections[2];
  int shift;
} WireNode; 
#endif
