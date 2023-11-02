#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: the given node
 *
 * Return: the uncle of the given node else NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent, *parent, *uncle;

	if (!node || !(node->parent) || !(node->parent->parent))
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;
	uncle = (grandparent->left == parent ? grandparent->right :
		grandparent->left);
	return (uncle);
}
