#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * swapNode - swap Node.
 * @myNode: pointer to the first node of the list
 * Return: void
 */
void swapNode(heap_t **myNode)
{
	heap_t *move;
	int tmp;

	for (move = *myNode; move->parent; move = move->parent)
		if (move->n > move->parent->n)
		{
			tmp = move->parent->n;
			move->parent->n = move->n;
			move->n = tmp;
			*myNode = move->parent;
		}
}

/**
 * testx - find the parent node where to insert.
 * @root: root of the tree
 * Return: Pointer to the parent node.
 */
heap_t *testx(heap_t **root)
{
	heap_t *node = NULL;
	heap_t *array[100];
	int front = 0;
	int reer = 0;


	array[reer] = *root;
	while (2021)
	{
		node = array[front];
		front++;
		if (!node->left)
		{
			front = reer = 0;
			return (node);
		}
		else if (!node->right)
		{
			front = reer = 0;
			return (node);
		}
		else
		{
			reer = reer + 1;
			array[reer] = node->left;
			reer = reer + 1;
			array[reer] = node->right;
		}
	}
}
/**
 * heap_insert - Max HEAP insertion function.
 * @root: pointer to the first node of the tree
 * @value: number to be inserted
 * Return: Pointer to the new created node.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newNode = NULL;
	heap_t *parentNode = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	parentNode = testx(root);
	newNode = binary_tree_node(parentNode, value);
	if (!parentNode->left)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;

	if (newNode->n > parentNode->n)
		swapNode(&newNode);
	return (newNode);
}