#include <stdio.h>
#include "./value.h"
#include "./node.h"
#include <assert.h>

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
