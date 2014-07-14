#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_hash.h"
#include "xor_hash.h"
#include "rotating.h"
#include "djb_hash.h"
#include "map.h"

void stripline(char *str) {
  int nn;

  nn = strlen(str) - 1;

  if (str[nn] == '\n')
    str[nn] = '\0';
}

void runner(const char *name, char *str, size_t len) {
  int i, hash;

  for (i = 0; i < (sizeof(map) / sizeof(map[0])); i++) {
    if (!strcmp(map[i].name, name) && map[i].func) {
      hash = map[i].func(str, len);
    }
  }

  printf("%s: %d\n", name, hash);
}

int main() {
  char buf[4096];
  ssize_t n;
  char *str = NULL;
  size_t len = 0;

  while ((n = read(STDIN_FILENO, buf, sizeof buf))) {
    if (n < 0) {
      if (errno == EAGAIN)
        continue;
      perror("read");
      break;
    }
    str = realloc(str, len + n + 1);
    memcpy(str + len, buf, n);
    len += n;
    str[len] = '\0';
  }

  stripline(str);

  runner("add", str, len);
  runner("xor", str, len);
  runner("rot", str, len);
  runner("djb", str, len);

  free(str);

  return 0;
}
