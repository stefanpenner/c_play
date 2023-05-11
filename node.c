#include <stdio.h>
#include "./value.h"
#include "./node.h"

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
    node = node->next;

    if (value != NULL) {
      if (value->type == LIST) {
        Node_printf((Node*) value->data);
      } else {
        Value_printf(value);
      }
    }
  }

  printf(")");
}

