#ifndef _IO_H_
#define _IO_H_

#include "graduate.h"
#include "class.h"
#include <stdio.h>
#include <stdlib.h>

int  graduate_read_txt(Graduate *gr, FILE *in);
int  graduate_read_bin(Graduate *gr, FILE *in);
void graduate_write_bin(Graduate *gr, FILE *out);
void class_print(Class *cl);

#endif