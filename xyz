#include "binary_trees.h"

/**
 * binary_tree_insert_right - creates a binary tree nodde and inserts it into a
 *	given parent node
 *
 * @parent: the parent node
 * @value: value to be inserted
 *
 * Return: the pointer to the node if successful else NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;

	if (parent->right == NULL)
	{
		parent->right = new_node;
		new_node->parent = parent;
	}
	else
	{
		temp = parent->right;
		parent->right = new_node;
		new_node->parent = parent;
		new_node->right = temp;
		temp->parent = new_node;
	}

	return (new_node);
}
