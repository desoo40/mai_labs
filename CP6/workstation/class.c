#include "class.h"

Class *class_create()
{
	Class *class = (Class*) malloc(sizeof(class));

	class->issue = 0;
	class->letter = 0;
	class->male_qty = 0;
	class->female_qty = 0;

	return class;
}