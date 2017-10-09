#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#define MAX_BUFFER 8

struct buffer_type
  {
  unsigned char *head;
  unsigned char *tail;
  unsigned char *buffer;
  };

enum error_type{OK,BUFFER_OVER_FLOW,EMPTY_BUFFER,POINTER_ERROR,BUFFER_FULL};
  
void init_buffer(struct buffer_type *b, unsigned char *buffer);
void empty_buffer(struct buffer_type *b);
signed int get_buffer_state(struct buffer_type b, error_type *err);
int add_char_to_buffer(struct buffer_type *b, unsigned char c, error_type *err);
unsigned char get_char_from_buffer(struct buffer_type *b, error_type *err);
int print_buffer(struct buffer_type b, error_type *err);
int add_string_to_buffer(struct buffer_type *b, unsigned char *s, error_type *err);
int  get_string_from_buffer(struct buffer_type *b, unsigned char *dest, int len, error_type *err);
int my_strlen(unsigned char *c);