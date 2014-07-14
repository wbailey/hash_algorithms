#include <stdio.h>
#include <string.h>
#include "add_hash.h"
#include "xor_hash.h"
#include "rotating.h"
#include "djb_hash.h"
#include "map.h"

void runner(const char *name, char *str, size_t len) {
  int i, hash;

  for (i = 0; i < (sizeof(map) / sizeof(map[0])); i++) {
    if (!strcmp(map[i].name, name) && map[i].func) {
      hash = map[i].func(str, len);
    }
  }

  printf("%s: %d\n", name, hash);
}
