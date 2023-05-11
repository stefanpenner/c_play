#include <stdlib.h>
#include "./value.h"

void Value_toString(Value *value, char* result) {
  switch (value->type) {
    case INT:
      snprintf(result, sizeof(result), "%d", (int) (size_t) value->data);
      break;
    case ATOM:
      snprintf(result, sizeof(result), "%s", (char *) value->data);
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
