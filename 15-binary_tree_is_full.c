#include "binary_trees.h"

int is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_full(tree));
}

/**
 * is_full - Checks if a binary tree is full recursively.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is not NULL, otherwise 1.
 */
int is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((!tree->left && tree->right) ||
		(tree->left && !tree->right) ||
		!is_full(tree->left) || !is_full(tree->right))
			return (0);

	}
	return (1);
}
