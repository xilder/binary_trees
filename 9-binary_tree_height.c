#include "binary_trees.h"
/**
 * binary_tree_height - gets the height of the tree
 *
 * @tree:pointer to the
 *
 * Return: the height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (0);

	height_l = (1 + binary_tree_height(tree->left));
	height_r = (1 + binary_tree_height(tree->right));

	return (height_l > height_r ? height_l : height_r);
}
