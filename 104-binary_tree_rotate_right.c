#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates the node right
 *
 * @tree: the node given
 *
 * Return: return a pointer to the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left, *tmp;

	if (!tree || !(tree->left))
		return (NULL);

	tmp = tree;
	left = tmp->left;
	left->parent = tmp->parent;
	if (tmp->parent)
		tmp->parent->left = left;
	tmp->left = left->right;
	if (left->right)
		left->right->parent = tmp;
	left->right = tmp;
	tmp->parent = left;

	return (left);
}
	

