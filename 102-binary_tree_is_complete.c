#include "binary_trees.h"

/**
 * binary_tree_hc - returns height of tree or zero
 *
 * @tree: pointer to the root
 *
 * Return: height of tree if complete else zero
 */
int binary_tree_hc(binary_tree_t *tree)
{
	int l, r;
	if (!(tree->left))
		return (0);
	if (!(tree->left->left))
		return (1);
	l = 1 + binary_tree_hc(tree->left);
	r = 1 + binary_tree_hc(tree->right);

	if (l == 2 && r == 1)
		return 0;

	return (l - r >= 0 && l - r <= 1 ? l : 0);
}

/**
 * binary_tree_is_complete - checks if the tree is complete given a root node
 *
 * @tree: root node
 *
 * Return: 1 if perfect else 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int l, r;
	binary_tree_t *node = (binary_tree_t *) tree;

	if (!node)
		return (0);
	if (!(node->left) && !(node->right))
		return (1);
	l = binary_tree_hc(tree->left);
	r = binary_tree_hc(tree->right);

	if (l == 0 && r == 0)
		return 0;
	return (l - r >= 0 && l - r <= 1 ? 1 : 0);
}
