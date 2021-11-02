#include "binary_trees.h"

/**
 * createNewNode - create node
 *
 * @parent: parent of the created node
 * @n: Size of the array
 * Return: new node
 */
avl_t *createNewNode(avl_t *parent, size_t n)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	return (node);
}

/**
 * createAvlTree - build an AVL tree from an array
 *
 * @array: sorted array
 * @start: first index
 * @end: last index
 * @parent: parent of the created node
 *
 * Return: root of the tree
 */
avl_t *createAvlTree(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = createNewNode(parent, array[mid]);
	if (!root)
		return (NULL);

	if (start != mid)
		root->left = createAvlTree(array, start, mid - 1, root);
	if (end != mid)
		root->right = createAvlTree(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: The a
 * @size: size of the array
 * Return: pointer to the root of the tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array)
		return (NULL);

	return (root = createAvlTree(array, 0, size - 1, NULL));
}
