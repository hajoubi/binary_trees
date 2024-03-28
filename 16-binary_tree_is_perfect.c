#include "binary_trees.h"


int is_perfect(int Level, int Depth, const binary_tree_t *tree);
int finde_depth(const binary_tree_t *tree);


/**
 * finde_depth - finde_depth
 * @tree: A pointer to the root node of the tree to check.
 * Return: depth
*/
int finde_depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		tree = tree->left;
		d++;
	}
	return (d);
}
/**
 * is_perfect - check if the tree is perfect
 * @Level: num of levels
 * @Depth: depth of the tree
 * @tree: A pointer to the root node of the tree to check.
 * Return: 0 || 1
*/
int is_perfect(int Level, int Depth, const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (Depth == Level + 1);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect(Level + 1, Depth, tree->left) &&
	 is_perfect(Level + 1, Depth, tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int Depth = 0;
	int level = 0;

	Depth = finde_depth(tree);
	return (is_perfect(level, Depth, tree));
}
