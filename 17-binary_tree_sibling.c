#include "binary_trees.h"

/**
 * binary_tree_sibling - finds thr sibling of a node
 *
 * @node: the given node
 *
 * Return: the sibling of the given node else NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent, *sibling;

	if (!node || !(node->parent))
		return (NULL);

	parent = node->parent;
	sibling = parent->left == node ? parent->right : parent->left;
	return (sibling);
}
