#include "runner.h"

int main() {
  struct Input *input = Input_create();

  runner("add", input);
  runner("xor", input);
  runner("rot", input);
  runner("djb", input);

  Input_destroy(input);

  return 0;
}
