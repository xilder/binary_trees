#include "binary_trees.h"

/**
 * binary_tree_h - returns height of tree or zero
 *
 * @tree: pointer to the root
 *
 * Return: height of tree if equal else zero
 */
int binary_tree_h(binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);
	l = 1 + binary_tree_h(tree->left);
	r = 1 + binary_tree_h(tree->right);
	return (l > r ? l : r);
}

/**
 * binary_level_order - prints the nodes at a given level
 *
 * @node: node given
 * @level: level given
 * @func: print function
 */

void binary_level_order(const binary_tree_t *node,
		int level, void (*func)(int))
{
	if (level == 0)
		func(node->n);
	else
	{
		binary_level_order(node->left, level - 1, func);
		binary_level_order(node->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverses a binary tree using level-orderly
 *
 * @tree: pointer to the root node
 * @func: pointer to the func function
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height;
	binary_tree_t *node = (binary_tree_t *)tree;

	if (!tree)
		return;

	height = binary_tree_h(node);

	for (int level = 0; level < height; level++)
		binary_level_order(tree, level, func);
}
