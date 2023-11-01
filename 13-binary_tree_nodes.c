#include "binary_trees.h"
/**
 * binary_tree_nodes - gets the number of nodes in the tree
 *
 * @tree: pointer to the tree
 *
 * Return: the number of nodes in the tree if successful
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (0);

	return (binary_tree_nodes(tree->left)
			+ binary_tree_nodes(tree->right) + 1);
}
