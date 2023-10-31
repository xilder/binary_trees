#include "binary_trees.h"
/**
 * binary_tree_postorder - traverses the binary tree in a postorderly fashion
 *
 * @tree: root node of the tree
 * @func: a function to print a node's value
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->right, func);
	func(tree->n);
	binary_tree_postorder(tree->left, func);
}
