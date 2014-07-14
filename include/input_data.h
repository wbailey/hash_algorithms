struct Input {
  char *data;
  size_t length;
};

void Input_destroy(struct Input *);

struct Input * Input_create();
