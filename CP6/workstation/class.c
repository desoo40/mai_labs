#include "class.h"

Class *class_create(Graduate *graduate)
{
	Class *class = (Class*) malloc(sizeof(class));

	class->issue = graduate->issue;
	class->letter = graduate->class_letter;
	class->male_qty = 0;
	class->female_qty = 0;

	return class;
}