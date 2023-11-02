#include "binary_trees.h"

/**
 * binary_tree_depth - gets the depth of the tree
 *
 * @tree:pointer to the node
 *
 * Return: the deptg of the tree
 */
int binary_tree_d(const binary_tree_t *tree)
{
	size_t depth;
	if (!tree)
		return (0);
	if (!(tree->parent))
		return (0);
	depth = (1 + binary_tree_d(tree->parent));
	return (depth);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two given nodes
 *
 * @first: first node
 * @second: second node
 *
 * Return: the common ancestor else NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	int depth_f, depth_s;

	if (!first || !second)
		return (NULL);

	depth_f = binary_tree_d(first);
	depth_s = binary_tree_d(second);

	while (depth_f > depth_s)
	{
		first = first->parent;
		depth_f--;
	}
	while (depth_s > depth_f)
	{
		second = second->parent;
		depth_s--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
