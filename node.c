#include <stdio.h>
#include "./value.h"
#include "./node.h"
#include <assert.h>

Node* Node_new() {
  Node *result = malloc(sizeof(Node));
  result->data = NULL;
  result->descendant = NULL;
  result->next = NULL;

  return result;
}

void Node_printf(Node *node) {
  printf("(");

  int i = 0;
  int first = 0;

  while (node != NULL) {
    if (i++ > 50) {
      // TODO: this is a hack to prevent infinite loops
      return;
    }

    if (first == 0) {
      first = 1;
    } else {
      printf(" ");
    }

    Value* value = node->data;

    // TODO: maybe be more explicit about a node who points to a value, or a
    // node which points to a list
    if (value) {
      Value_printf(value);
    } else if (node->descendant) {
      Node_printf(node->descendant);
    } else {
      // an empty list
    }

    node = node->next;
  }
  printf(")");
}



void _Node_from_string(char* string, Node* result) {
  Node *previous = result;
  // array of nodes

  size_t len = strlen(string);
  for (size_t i = 1; i < len; i++) {
    switch (string[i - 1]) {
      case '(':
        {
          Node *descendant = Node_new();
          previous->descendant = descendant;
          _Node_from_string(&string[i], descendant);
        }
        break;
      case ')':
        break;
    }
  }
}

Node* Node_from_string(char* string) {
  Node *result = Node_new();
  _Node_from_string(string, result);
  return result;
}

