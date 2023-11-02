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

/**
 * binary_tree_is_perfect - checks if the tree is perfect given a root node
 *
 * @tree: root node
 *
 * Return: 1 if perfect else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);

	l = binary_tree_h(tree->left);
	r = binary_tree_h(tree->right);

	return (l == 0 || r == 0 ? 0 :
			l == r ? 1 : 0);
}
