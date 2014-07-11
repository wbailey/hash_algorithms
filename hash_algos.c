#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_hash.h"
#include "xor_hash.h"
#include "rotating.h"
#include "djb_hash.h"

int main() {
  char *buffer = NULL;
  int hash, nn;
  size_t len;

  getline(&buffer, &len, stdin);

  nn = strlen(buffer) - 1;

   if (buffer[nn] == '\n')
     buffer[nn] = '\0';

  printf("string length: %lu\n", strlen(buffer));

  hash = add_hash(buffer, len);
  printf("add: %d\n", hash);

  hash = xor_hash(buffer, len);
  printf("xor: %d\n", hash);

  hash = rotating_hash(buffer, len);
  printf("rotating: %d\n", hash);

  hash = djb_hash(buffer, len);
  printf("djb: %d\n", hash);

  free(buffer);

  return 0;
}
