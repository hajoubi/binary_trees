#include "binary_trees.h"
/**
 * binary_tree_uncle - Finds the uncle of a node.
 *
 * @node: A pointer to the node to find the uncle.
 *
 * Return: NULL if node is NULL or node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *garnd_parent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	garnd_parent = node->parent->parent;

	if (garnd_parent->right == node->parent)
		return (garnd_parent->left);

	else if (garnd_parent->left == node->parent)
		return (garnd_parent->right);

	else
		return (NULL);

}
