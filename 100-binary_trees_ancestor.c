#include "binary_trees.h"

/**
 * depth - Calculate the depth of a node in a binary tree.
 *
 * @node: Pointer to the node whose depth is to be calculated.
 *
 * Return: Depth of the node in the binary tree.
 */
int depth(const binary_tree_t *node)
{
	int d = 0;

	while (node->parent)
	{
		node = node->parent;
		d++;
	}
	return (d);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int first_depth = 0, second_depth = 0;

	if (!first || !second)
		return (NULL);

	first_depth = depth(first);
	second_depth = depth(second);

	while (first_depth > second_depth)
	{
		first_depth--;
		first = first->parent;
	}
	while (second_depth > first_depth)
	{
		second_depth--;
		second = second->parent;
	}
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
