#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_hash.h"
#include "xor_hash.h"
#include "rotating.h"
#include "djb_hash.h"
#include "map.h"

void stripline(char *buffer) {
  int nn;

  nn = strlen(buffer) - 1;

  if (buffer[nn] == '\n')
    buffer[nn] = '\0';
}

void runner(const char *name, char *buffer, size_t len) {
  int i, hash;

  for (i = 0; i < (sizeof(map) / sizeof(map[0])); i++) {
    if (!strcmp(map[i].name, name) && map[i].func) {
      hash = map[i].func(buffer, len);
    }
  }

  printf("%s: %d\n", name, hash);
}

int main() {
  char *buffer = NULL;
  size_t len;

  getline(&buffer, &len, stdin);
  stripline(buffer);

  runner("add", buffer, len);
  runner("xor", buffer, len);
  runner("rot", buffer, len);
  runner("djb", buffer, len);

  free(buffer);

  return 0;
}
