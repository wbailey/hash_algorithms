#include <stdlib.h>
#include <string.h>

unsigned rotating_hash( void *key, int len ) {
  unsigned char *p = key;
  unsigned h = 0;
  int i;

  for ( i = 0; i < len; i++ )
    h = ( h << 4 ) ^ ( h >> 28 ) ^ p[i];

  return h;
}

