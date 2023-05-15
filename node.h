#ifndef Node_h
#define Node_h
typedef struct Value Value;
typedef struct Node
{
  struct Node *next;
  struct Node *descendant;
  Value *data;
} Node;

#endif
