#include "binary_trees.h"

/**
 * binary_tree_is_full - function to determine if the tree is full
 *
 * @tree: pointer to root
 *
 * Return: 1 if the tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return (0);
    }

    if (tree->left == NULL && tree->right == NULL)
    {
        return (1);
    }

    if (tree->left && tree->right)
    {
        int left = binary_tree_is_full(tree->left);
        int right = binary_tree_is_full(tree->right);
        if (left == 1 && right == 1)
        {
            return (1);
        }
    }

    return (0);
}
