#include "./type.h"

char * Type_toString(enum Type type) {
  switch  (type) {
    case INT:
      return "INT";
    case FLOAT:
      return "FLOAT";
    case CHAR:
      return "CHAR";
    case ATOM:
      return "ATOM";
    default:
      return "UNKNOWN";
  }
}

