#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 *
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{

	binary_tree_t *new_root, *tmp;

	if (!tree || !tree->left)
		return (tree);

	new_root = tree->left;
	tmp = new_root->right;
	new_root->right = tree;
	tree->left = tmp;
	if (tmp)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = new_root;
	new_root->parent = tmp;
	if (tmp)
	{
		if (tmp->left == tree)
			tmp->left = new_root;
		else
			tmp->right = new_root;
	}
	return (new_root);
}
