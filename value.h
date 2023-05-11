#ifndef value_h
#define value_h
#include "./type.h"
typedef struct Value
{
  enum Type type;
  void* data;
  // TODO: It is critical that this is correct, or bad things will
  // happen. We should explore if there is a better approach.
  int size;
} Value;

void Value_toString(Value *value, char* result);
void Value_printf(Value *value);
#endif
