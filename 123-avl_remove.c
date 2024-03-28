#include "binary_trees.h"
/**
 * avl_remove - Removes a node from an AVL tree.
 *
 * @root: A pointer to the root node of the tree for removing a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after
 *         removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
}

/**
 * bst_remove - Remove a node from a BST tree.
 *
 * @root: Root of the tree.
 * @value: Node with this value to remove.
 *
 * Return: The tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
}

/**
 * remove_type - Function that removes a node depending of its children.
 *
 * @root: Node to remove.
 *
 * Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
}

/**
 * successor - Get the next successor i mean the min node in the right subtree.
 *
 * @node: Tree to check.
 *
 * Return: The min value of this tree.
 */
int successor(bst_t *node)
{
}

/**
 * bal - Measures balance factor of a AVL.
 *
 * @tree: Tree to go through.
 *
 * Return: Balanced factor.
 */
void bal(avl_t **tree)
{
}
