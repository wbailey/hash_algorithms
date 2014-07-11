unsigned djb_hash( void *key, int len ) {
  unsigned char *p = key;
  unsigned h = 0;
  int i;

  for ( i = 0; i < len; i++ )
    h = 33 * h + p[i];

  return h;
}
