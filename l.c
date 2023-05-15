// c program that prints hello world
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./type.h"
#include "./value.h"
#include "./node.h"

void test_Node_printf(void) {
  printf("test_node_printf:\n");
  Value one = {
    .type = INT,
    .data = 1,
    .size = 1,
  };

  Value two = {
    .type = INT,
    .data = 2,
    .size = 1,
  };

  Value three = {
    .type = INT,
    .data = 3,
    .size = 1,
  };

  Value four = {
    .type = INT,
    .data = 4,
    .size = 1,
  };

  Node empty_list = {
    .data = NULL,
    .next = NULL,
  };

  Node list_of_one = {
    .data = &three,
    .next = NULL,
  };

  Node list_of_two = {
    .data = &two,
    .next = &list_of_one,
  };

  Node list_of_three = {
    .data = &one,
    .next = &list_of_two,
  };

  Node list_of_empty_list = {
    .descendant = &empty_list,
  };

  Node list_of_three_with_extra = {
    .descendant = &list_of_one,
    .next = &list_of_three,
  };

  Node mixed_list = {
    .descendant = &empty_list,
    .next = &list_of_three_with_extra,
  };

  /* printf("  1: "); */
  /* Node_printf(&empty_list); */
  /* printf("\n"); */
  printf("  2: ");
  Node_printf(&list_of_one);
  printf("\n");
  printf("  3: ");
  Node_printf(&list_of_two);
  printf("\n");
  printf("  4: ");
  Node_printf(&list_of_three);
  printf("\n");
  printf("  5: ");
  Node_printf(&list_of_empty_list);
  printf("\n");
  printf("  6: ");
  Node_printf(&list_of_three_with_extra);
  printf("\n");
  printf("  7: ");
  Node_printf(&mixed_list);
  printf("\n");
}

void test_define_foo_five() {
  printf("test_define_foo_five:\n");
  /*
   * (define foo 1)
   * node (val define)
   * node (val foo)
   * node (val 1)
   */

  Value v_define = {
    .type = ATOM,
    .data = "define",
    .size = 6,
  };

  Value v_foo = {
    .type = ATOM,
    .data = "foo",
    .size = 3,
  };

  Value v_one = {
    .type = INT,
    .data = 1,
    .size = 1,
  };

  Node n_one = {
    .data = &v_one,
    .next = NULL,
  };

  Node n_foo = {
    .data = &v_foo,
    .next = &n_one,
  };

  Node n_define = {
    .data = &v_define,
    .next = &n_foo,
  };

  printf("  8: ");
  Node_printf(&n_define);
}

void _Node_from_string(char* string, Node* result) {
  Node *previous = result;
  // array of nodes

  size_t len = strlen(string);
  for (size_t i = 1; i < len; i++) {
    switch (string[i - 1]) {
      case '(':
        {
          Node *descendant= malloc(sizeof(Node));
          descendant->data = NULL;
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
  printf("  %s:", string);
  Node *result = malloc(sizeof(Node));
  result->data = NULL;
  result->descendant = NULL;
  result->next = NULL;

  _Node_from_string(string, result);

  return result;
}

void test_Node_from_string() {
  printf(" test_Node_from_string:\n");
  printf("  ");
  Node_printf(Node_from_string("()"));
  printf("\n --- \n");
  Node_printf(Node_from_string("(())"));
  printf("\n  --- \n ");
  Node_printf(Node_from_string("((()))"));
  printf("\n  --- \n ");
  Node_printf(Node_from_string("((1))"));
  printf("\n  --- \n ");
  Node_printf(Node_from_string("(1 1)"));
  printf("\n  --- \n ");
  Node_printf(Node_from_string("(1 (1) 1)"));
  printf("\n  --- \n ");
  Node_printf(Node_from_string("(1 ((1)) 1)"));
}

int main(void)
{
  test_Node_printf();
  test_define_foo_five();
  test_Node_from_string();
  printf("\n");
  return 0;

}
