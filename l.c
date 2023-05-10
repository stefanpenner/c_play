// c program that prints hello world
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum Type {INT, LIST, FLOAT, CHAR, STRING, OPERATION};

char * Type_toString(enum Type type) {
  switch  (type) {
    case INT:
      return "INT";
    case LIST:
      return "LIST";
    case FLOAT:
      return "FLOAT";
    case CHAR:
      return "CHAR";
    case STRING:
      return "STRING";
    case OPERATION:
      return "OPERATION";
    default:
      return "UNKNOWN";
  }
}

typedef struct Value
{
  enum Type type;
  void* data;
  int size;
} Value;

typedef struct Node
{
  struct Node *next;
  Value *data;
} Node;

void Value_toString(Value *value, char* result) {
  switch (value->type) {
    case INT:
      snprintf(result, sizeof(result), "%d", (int) (size_t) value->data);
      break;
    default:
      snprintf(result, sizeof(result), "%s", "??");
  }
}

void Value_printf(Value *value) {
  char * result[value->size + 1]; // TODO: cleanup sizing
  Value_toString(value, result);
  printf("%s::%s", result, Type_toString(value->type));
}

void Node_printf(Node *node) {
  printf("(");
  int i = 0;
  bool first = true;

  while (node != NULL) {
    if (i++ > 10) {
      return;
    }

    if (first) {
      first = false;
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


listOf(Node *node, Value *values, size_t length) {
  for (int i = 0; i < length; i++) {
    Node *next = node->next;
    node->next = malloc(sizeof(Node));
    node->data = &values[i];
    node = node->next;
    node->next = next;
  }
}

int main(void)
{
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

  Value empty_list_value = {
    .type = LIST,
    .data = &empty_list,
  };

  Node list_of_one= {
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

  Value list_of_three_value = {
    .type = LIST,
    .data = &list_of_three
  };

  Node list_of_empty_list = {
    .data = &empty_list_value,
  };

  Node list_of_three_with_extra = {
    .data = &list_of_three_value,
    .next = &list_of_three,
  };

  Node mixed_list = {
    .data = &empty_list_value,
    .next = &list_of_three_with_extra,
  };


  Node node;
  Value values[4] = {
    one,
    two,
    one,
    two
  };

  listOf(&node, &values, 4);

  Node_printf(&node);

/*   printf("1: "); */
/*   Node_printf(&empty_list); */
/*   printf("\n"); */
/*   printf("2: "); */
/*   Node_printf(&list_of_one); */
/*   printf("\n"); */
/*   printf("3: "); */
/*   Node_printf(&list_of_two); */
/*   printf("\n"); */
/*   printf("4: "); */
/*   Node_printf(&list_of_three); */
/*   printf("\n"); */
/*   printf("5: "); */
/*   Node_printf(&list_of_empty_list); */
/*   printf("\n"); */
/*   printf("6: "); */
/*   Node_printf(&list_of_three_with_extra); */
/*   printf("\n"); */
/*   printf("7: "); */
/*   Node_printf(&mixed_list); */
  printf("\n");
}
