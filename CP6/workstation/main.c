#include "graduate.h"
#include "trees.h"
#include "class.h"
#include "io.h"

void detour_letter(Letter_node *node)
{
	if (node == NULL)
		return;

	if (node->class->male_qty > node->class->female_qty)
		class_print(node->class);

	if (node->left != NULL)
		detour_letter(node->left);
	if (node->right != NULL)
		detour_letter(node->right);

	return;
}

void detour_year(Year_node *node)
{
	if (node == NULL)
		return;

	detour_letter(node->l_tree->root);

	if (node->left != NULL)
		detour_year(node->left);
	if (node->right != NULL)
		detour_year(node->right);
	
	return;
}

void find_male_dominate_classes(Year_tree *tree)
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

	if (!in) {
		fprintf(stderr, "Error: can't open file\n");
		return 0;
	}

	Year_tree *year_tree = NULL;
	Graduate graduate;

	while (graduate_read_bin(&graduate, in)) {

		if (year_tree == NULL)
			year_tree = year_tree_create(&graduate);
		else
			year_tree_add_grad(year_tree->root, &graduate);
	}

	printf("Date   Letter     Male    Female\n");
	find_male_dominate_classes(year_tree);

	year_tree_destroy(&year_tree);
	fclose(in);

	return 0;
}