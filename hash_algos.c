#include "runner.h"
#include "input_data.h"

int main() {
  struct Input *i = Input_create();

  runner("add", i->data, i->length);
  runner("xor", i->data, i->length);
  runner("rot", i->data, i->length);
  runner("djb", i->data, i->length);

  Input_destroy(i);

  return 0;
}
