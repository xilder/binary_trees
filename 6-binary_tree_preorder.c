#include "binary_trees.h"
/**
 * binary_tree_preorder - traverses the binary tree in a preoderly fashion
 *
 * @tree: root node of the tree
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
