#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates the node left
 *
 * @tree: the node given
 *
 * Return: return a pointer to the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right, *tmp;

	if (!tree || !(tree->right))
		return (NULL);

	tmp = tree;
	right = tmp->right;
	right->parent = tmp->parent;
	if (tmp->parent)
		tmp->parent->right = right;
	tmp->right = right->left;
	if (right->left)
		right->left->parent = tmp;
	right->left = tmp;
	tmp->parent = right;

	return (right);
}
