#include "binary_trees.h"

/**
 * binary_tree_delete - deletes the entire tree
 *
 * @tree: pointer to the tree
 */

void binary_tree_delete(binary_tree_t *tree)
{

	binary_tree_t *temp;

	if (tree == NULL)
		return;

	temp = tree->right;
	binary_tree_delete(tree->left);
	free(tree);
	binary_tree_delete(temp);
}
