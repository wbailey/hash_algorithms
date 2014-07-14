#include <stdio.h>
#include <string.h>
#include "add_hash.h"
#include "xor_hash.h"
#include "rotating.h"
#include "djb_hash.h"
#include "map.h"
#include "input_data.h"

void runner(const char *name, struct Input *input) {
  int i, hash;

  for (i = 0; i < (sizeof(map) / sizeof(map[0])); i++) {
    if (!strcmp(map[i].name, name) && map[i].func) {
      hash = map[i].func(input->data, input->length);
    }
  }

  printf("%s: %d\n", name, hash);
}
