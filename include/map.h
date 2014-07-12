const static struct {
  const char *name;
  unsigned (*func)(char *, int);
} map [] = {
  {"add", add_hash},
  {"xor", xor_hash},
  {"rot", rotating_hash},
  {"djb", djb_hash},
};
