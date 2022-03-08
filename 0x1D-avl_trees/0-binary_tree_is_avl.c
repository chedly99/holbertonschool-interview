#include "binary_trees.h"
#include <limits.h>

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	int l_height;
	int r_height;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + tree_height(tree->left);
	else
		l_height = 0;
	if (tree->right)
		r_height = 1 + tree_height(tree->right);
	else
		r_height = 0;

	if (l_height > r_height)
		return (l_height);
	else
		return (r_height);
}

/**
 * bst_h - checks if valid BST
 * @tree: pointer to root node being checked
 * @min: integer
 * @max: integer
 *
 * Return: 1 if valid BST, 0 on failure
 */
int bst_h(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_h(tree->left, min, tree->n - 1) &&
		bst_h(tree->right, tree->n + 1, max));
}

/**
 * tree_is_bst - checks if a binary tree is a nid Binary Search Tree
 * @tree: a pointer to the node node of the tree to check
 * Return: 1 if tree is a nid BST, and 0 otherwise
 * If tree is NULL, return 0
 */
int tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_h(tree, INT_MIN, INT_MAX));
}

/**
 * avl_check - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int avl_check(const binary_tree_t *tree)
{
	int diff, heightL = 0, heightR = 0;

	if (!tree)
		return (1);

	if (!tree_is_bst(tree))
		return (0);

	heightL = tree_height(tree->left);
	heightR = tree_height(tree->right);

	diff = abs(heightL - heightR);

	if (diff == 0 && avl_check(tree->left) && avl_check(tree->right))
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (avl_check(tree));
}