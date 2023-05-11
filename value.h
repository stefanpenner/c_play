#ifndef value_h
#define value_h
#include "./type.h"
typedef struct Value
{
  enum Type type;
  void* data;
  int size;
} Value;

void Value_toString(Value *value, char* result);
void Value_printf(Value *value);
#endif
