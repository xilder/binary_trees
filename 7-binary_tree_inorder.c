#include "binary_trees.h"
/**
 * binary_tree_inorder - traverses the binary tree in a inorderly fashion
 *
 * @tree: root node of the tree
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	binary_tree_preorder(tree->left, func);
	func(tree->n);
	binary_tree_preorder(tree->right, func);
}
