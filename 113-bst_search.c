#include "binary_trees.h"

/**
 * bst_search - finds a  value in bst
 *
 * @tree: root node of the tree
 * @value: value to be found
 *
 * Return: returns the node if found else NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node;

	if (!tree)
		return NULL;

	node = (bst_t *)tree;

	while (node && value != node->n)
	{
		if (value > node->n)
			node = node->right;
		else if (value < node->n)
			node = node->left;
	}

	return (node);
}
