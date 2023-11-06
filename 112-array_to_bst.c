#include "binary_trees.h"

/**
 * array_to_bst - transforms an array into a binary tree
 *
 * @array: a pointer to the array
 * @size: the size of the array
 *
 * Return: the root node if successfull else NULL
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	unsigned int i;

	if (!array || size < 1)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
