#include "binary_trees.h"

/**
 * bst_remove_no_children_helper - removes node if it has no childen
 *
 * @node: node to be removed
 * @root: root node
 *
 * Return: root
 */

bst_t *bst_remove_no_children_helper(bst_t *root, bst_t *node)
{
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	free(node);
	return (root);
}

/**
 * bst_remove_one_child_helper - removes if node has only one child
 *
 * @node: node to removed
 * @root: root node
 *
 * Return: root
 */

bst_t *bst_remove_one_child_helper(bst_t *root, bst_t *node)
{
	if (!(node->right))
	{
		if (node->parent->left == node)
			node->parent->left = node->left;
		if (node->parent->right == node)
			node->parent->right = node->left;
		node->left->parent = node->parent;
	}
	else
	{
		if (node->parent->left == node)
			node->parent->left = node->right;
		if (node->parent->right == node)
			node->parent->right = node->right;
		node->right->parent = node->parent;
	}
	free(node);
	return (root);
}

/**
 * bst_remove_one_child_no_parent_helper - helps to delete aa node
 *	with one child and no parent
 *
 * @node: node to be removed
 * @root: root node
 *
 * Return: root node
 */

bst_t *bst_remove_one_child_no_parent_helper(bst_t *root, bst_t *node)
{
	bst_t *tmp;

	if (!(node->right))
	{
		tmp = root;
		root = root->left;
		free(tmp);
		return (root);
	}
	else
	{
		tmp = root;
		root = root->right;
		free(tmp);
		return (root);
	}
}

/**
 * bst_remove_two_children_helper - helps to delete a node with two children
 *
 * @root: the root node
 * @node: the node to be deleted
 *
 * Return: the root node
 */

bst_t *bst_remove_two_children_helper(bst_t *root, bst_t *node)
{
	bst_t *tmp;

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

/**
 * bst_remove - deletes a node and replaces with it's inorder successor
 *
 * @root: pointer to the root
 * @value: value to be deleted
 *
 * Return: root node
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *tmp;

	node = tmp = root;
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
		return (bst_remove_no_children_helper(tmp, node));
	else if ((!(node->left) && node->right)
			|| (node->left && !(node->right)))
	{
		if (node->parent)
			return (bst_remove_one_child_helper(tmp, node));
		else
			return (bst_remove_one_child_no_parent_helper(tmp,
						node));
	}
	else
		return (bst_remove_two_children_helper(tmp, node));
}
