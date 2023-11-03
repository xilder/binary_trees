#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if the tree is complete given a root node
 *
 * @tree: root node
 *
 * Return: 1 if perfect else 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *node = (binary_tree_t *) tree;

	if (!node)
		return (0);
	if (!(node->left) && !(node->right))
		return (1);
	if (!(node->left) || !(node->right))
		return (0);

	return (binary_tree_is_complete(node->left)
			&& binary_tree_is_complete(node->right)
			? 1 : 0);
}
