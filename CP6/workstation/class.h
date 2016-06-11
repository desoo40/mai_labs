#pragma once
#ifndef _CLASS_H_
#define _CLASS_H_

#include "graduate.h"

typedef struct {
	Date issue;
	char letter;
	uint32_t male_qty;
	uint32_t female_qty;
} Class;

Class *class_create();

#endif