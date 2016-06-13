#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "stack.h"

void get_string(Stack *out);
bool is_char_operator(int c);
bool is_char_operand(int c);
bool is_dig(int c);
bool is_input_right(char *c);

#endif