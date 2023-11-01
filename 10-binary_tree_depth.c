#include "binary_trees.h"
/**
 * binary_tree_depth - gets the depth of the tree
 *
 * @tree:pointer to the node
 *
 * Return: the deptg of the tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);
	if (!(tree->parent))
		return (0);

	depth = (1 + binary_tree_depth(tree->parent));

	return (depth);
}
