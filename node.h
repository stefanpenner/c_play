#ifndef Node_h
#define Node_h
typedef struct Value Value;
typedef struct Node
{
  struct Node *next;
  Value *data;
} Node;

#endif
