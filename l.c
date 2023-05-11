// c program that prints hello world
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./type.h"
#include "./value.h"
#include "./node.h"

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

  Node_printf(&empty_list);
  printf("\n");
  printf("2: ");
  Node_printf(&list_of_one);
  printf("\n");
  printf("3: ");
  Node_printf(&list_of_two);
  printf("\n");
  printf("4: ");
  Node_printf(&list_of_three);
  printf("\n");
  printf("5: ");
  Node_printf(&list_of_empty_list);
  printf("\n");
  printf("6: ");
  Node_printf(&list_of_three_with_extra);
  printf("\n");
  printf("7: ");
  Node_printf(&mixed_list);
  printf("\n");
}
