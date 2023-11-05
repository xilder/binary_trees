#include "binary_trees.h"

/**
 * binary_tree_is_bst_helper - helper function
 *
 * @tree: root node
 * @min: min value
 * @max: max value
 *
 * Return: return 1 if it is a binary search tree else 0
 */

int binary_tree_is_bst_helper(binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (binary_tree_is_bst_helper(tree->left, min, tree->n - 1)
			&& binary_tree_is_bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a tree is a binary search tree
 *
 * @tree: root node
 *
 * Return: return 1 if it is a binary search tree else 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	binary_tree_t *node = (binary_tree_t *)tree;

	if (!node)
		return (0);
	return (binary_tree_is_bst_helper(node, INT_MIN, INT_MAX));
}
