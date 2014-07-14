#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include "input_data.h"

void input_strip(char *str) {
  int nn;

  nn = strlen(str) - 1;

  if (str[nn] == '\n')
    str[nn] = '\0';
}

void Input_destroy(struct Input *i) {
  assert(i != NULL);
  
  free(i->data);
  free(i);
}

struct Input * Input_create() {
  char buf[4096];
  ssize_t n;
  char *str = NULL;
  size_t len = 0;
  struct Input *d = malloc(sizeof(struct Input));
  assert(d != NULL);

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

  input_strip(str);

  d->data = str;
  d->length = len;

  return d;
}
