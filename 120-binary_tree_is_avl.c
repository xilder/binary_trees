#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: tree to measure the height of
 *
 * Return: height of the tree 0 if tree is NULL
 */

int binary_tree_h(binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (0);
	height_l = (1 + binary_tree_h(tree->left));
	height_r = (1 + binary_tree_h(tree->right));

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_avl_helper - helper that finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is avl 0 otherwise
 */

int binary_tree_is_avl_helper(binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + binary_tree_h(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_h(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left, min, tree->n - 1) &&
			binary_tree_is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - check if a binary tree is an AVL
 *
 * @tree: root node
 *
 * Return: 1 if true else 0;
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	binary_tree_t *node = (binary_tree_t *)tree;

	if (!tree)
		return (0);
	return (binary_tree_is_avl_helper(node, INT_MIN, INT_MAX));
}
