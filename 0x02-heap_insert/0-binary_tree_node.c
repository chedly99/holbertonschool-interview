#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - create a Binary tree
 * @parent: pointer to the parent node
 * @value: value to insert in the new Node
 * Return: Poiner to the created Node or NULL if it fails
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	/*new = malloc(sizeof(binary_tree_t));*/
	new = calloc(1, sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

