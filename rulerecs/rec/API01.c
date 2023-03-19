#include <stdio.h>
// By doiung Structure* safe I gurentee anything that I put into safe cannot be overwritin by a bufferover flow in name becuase it's put in the mermory before hand
struct Structure {
  struct Structure* safe;
  char name[20];
};

int main() {
  struct Structure test;

  strcpy(test.name,"Tim Lewis");

  printf("My name: %s\n", test.name);
  return 0;
}