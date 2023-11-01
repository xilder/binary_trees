#include "binary_trees.h"

/**
 * binary_tree_h - returns height of tree
 *
 * @tree: pointer to the root
 *
 * Return: height of tree
 */

int binary_tree_h(binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	l = 1 + binary_tree_h(tree->left);
	r = 1 + binary_tree_h(tree->right);

	return (l > r ? l : r);
}

/**
 * binary_tree_balance - checks the balance of a tree from a given root
 *
 * @tree: root node
 *
 * Return: the balance of the tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	l = binary_tree_h(tree->left);
	r = binary_tree_h(tree->right);

	return (l - r);
}
