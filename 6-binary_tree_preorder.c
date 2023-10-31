#include "binary_trees.h"
/**
 * binary_tree_preorder - traverses the binary tree in a preoderly fashion
 *
 * @tree: root node of the tree
 * @func: a function to print a node's value
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
