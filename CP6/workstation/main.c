#include "graduate.h"

typedef struct {
	Date issue;
	char letter;
	uint16_t male_qty;
	uint16_t female_qty;
} Class;

void detour_year(Avl_node *node)
{
	detour_letter(node->letter_tree->root);
}

void detour_letter(Avl_leteer_node *node)
{
	if (node->class->m > node->class->f)
		print_class(node->class);
}

void find_male_dominate_classes(Avl_tree *tree)
{
	detour_year(tree->root);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
        fprintf(stdout, "Usage:\n/main DataBase_FILE\n");
        exit(0);
    }

	FILE *in = fopen(argv[1], "r");

    if (!in)
        fprintf(stderr, "Error: can't open file\n");

	Avl_tree* year_tree = avl_tree_create();
	Graduate graduate;

	while (graduate_read_bin(&graduate, in))
		avl_tree_add_grad(year_tree, &graduate);

	find_male_dominate_classes(year_tree);

	return 0;
}