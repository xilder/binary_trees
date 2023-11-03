#include "binary_trees.h"

/**
 * binary_tree_h - returns height of tree or zero
 *
 * @tree: pointer to the root
 *
 * Return: height of tree if equal else zero
 */
int binary_tree_h(binary_tree_t *tree)
{
	int l, r;
	if (!tree)
		return (0);
	l = 1 + binary_tree_h(tree->left);
	r = 1 + binary_tree_h(tree->right);
	return (l == r ? l : 0);
}
