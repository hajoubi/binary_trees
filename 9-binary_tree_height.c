#include "binary_trees.h"
#include <stdio.h>

/**
 * max - Find maximum between two numbers.
 *
 * Return: maximum number
 * @num1: int 1
 * @num2: int 2
 */
size_t max(int num1, int num2)
{
	return ((num1 > num2) ? num1 : num2);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (max(binary_tree_height(tree->left)
												, binary_tree_height(tree->right)) + 1);
}
