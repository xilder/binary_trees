#include "binary_trees.h"

/**
 * bst_remove - deletes a node and replaces with it's inorder successor
 *
 * @root: pointer to the root
 * @value: value to be deleted
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = (bst_t *)root, *tmp;

	if (!root)
		return (NULL);

	while (node && value != node->n)
	{
		if (value > node->n)
			node = node->right;
		else if (value < node->n)
			node = node->left;
	}

	if (!node)
		return (NULL);
	if (!(node->left) && !(node->right))
	{
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = NULL;
			if (node->parent->right == node)
				node->parent->right = NULL;
		}
	}
	else if ((!(node->left) && node->right)
			|| (node->left && !(node->right)))
	{
		if (!(node->right))
		{
			if (node->parent)
			{
				if (node->parent->left == node)
					node->parent->left = node->left;
				if (node->parent->right == node)
					node->parent->right = node->left;
				node->left->parent = node->parent;
			}
			else
			{
				tmp = root;
				root = root->left;
				free(tmp);
				return (root);
			}
		}
		else
		{
			if (node->parent)
			{
				if (node->parent->left == node)
					node->parent->left = node->right;
				if (node->parent->right == node)
					node->parent->right = node->right;
				node->right->parent = node->parent;
			}
			else
			{
				tmp = root;
				root = root->right;
				free(tmp);
				return (root);
			}
		}
	}
	else
	{
		if (node->right->left)
		{
			node->n = node->right->left->n;
			free(node->right->left);
			node->right->left = NULL;
			return (root);
		}
		else
		{
			tmp = node->right;
			node->n = tmp->n;
			node->right = tmp->right;
			if (tmp->right)
				tmp->right->parent = node;
			free(tmp);
			return (root);
		}
	}
	free(node);
	return (root);
}
