#include "binary_trees.h"

/**
 * bst_insert - inserts a node at the corrct place in a binary search tree
 *
 * @tree: root node
 * @value: value of the node
 *
 * Return: the pointer to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *tmp, *second;

	if (!tree)
		return NULL;
	if (*tree == NULL)
		return *tree = binary_tree_node(NULL, value);

	tmp = *tree;

	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else
			return (NULL);
	}

	new_node = binary_tree_node(NULL, value);
	
	if (value < second->n)
		second->left = new_node;
	else
		second->right = new_node;
	
	new_node->parent = second;

	return (new_node);
}
