#include "binary_trees.h"

/**
 * tree_height - Finds the height of a given binary tree
 * @tree: given tree
 * Return: returns total height of tree
 */
size_t tree_height(const heap_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = tree_height(tree->left) + 1;
	right_height = tree_height(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * tree_size - Finds the size of a given binary tree (total # of nodes)
 * @root: The root node of the binary tree
 * Return: returns the total number of nodes
 */
int tree_size(heap_t *root)
{
	if (root == NULL)
		return (0);
	else
		return (tree_size(root->left) + 1 + tree_size(root->right));
}

/**
 * find_last_node - prints a decimal number as binary
 * @size: The size of the binary tree we are searching
 * @binary: This is a pointer to a malloc'd array in the driver code
 * where the binary path to the final node will be indexed
 * @current_index: The current index 'binary' is current on when
 * when saving a node position
 */
void find_last_node(unsigned long int size, int *binary, int current_index)
{
	unsigned long int temp = size;

	if (temp == 1)
		return;
	if (temp > 1)
		find_last_node(temp >> 1, binary, current_index - 1);
	binary[current_index] = (temp & 1);
}

/**
 * rm_last_node - removes the final node of a binary tree
 * @root: The root node of the tree we are removing from
 * Return: returns the ->n value of the removed node
 */
int rm_last_node(heap_t *root)
{
	int size = tree_size(root);
	heap_t *temp_head = root;
	int height = tree_height(root) - 1;
	int *binary = malloc(sizeof(int) * height);
	int i;
	int hold_n1;

	find_last_node(size, binary, height - 1);

	for (i = 0; i < height; i++)
	{
		if (binary[i] == 1)
			temp_head = temp_head->right;
		else if (binary[i] == 0)
			temp_head = temp_head->left;
	}

	if (binary[i - 1] == 1)
		temp_head->parent->right = NULL;
	else if (binary[i - 1] == 0)
		temp_head->parent->left = NULL;
	hold_n1 = temp_head->n;
	free(temp_head);
	free(binary);

	return (hold_n1);
}

/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: A double pointer to the root node of the max binary heap
 * Return: returns 0 on failure or the -> n value of the extracted root
 */
int heap_extract(heap_t **root)
{
	heap_t *head = NULL;
	int hold_n1, hold_n2;

	if (root == NULL || *root == NULL)
		return (0);

	hold_n1 = rm_last_node(*root);
	head = *root;

	if (head->right == NULL && head->left == NULL)
	{
		hold_n2 = head->n;
		*root = NULL;
		free(head);
		return (hold_n2);
	}

	while (head->right != NULL || head->left != NULL)
	{
		hold_n2 = head->n;
		if (head->right == NULL || head->left->n >= head->right->n)
		{
			head->n = head->left->n;
			head->left->n = hold_n2;
			head = head->left;
		}
		else if (head->left == NULL || head->right->n >= head->left->n)
		{
			head->n = head->right->n;
			head->right->n = hold_n2;
			head = head->right;
		}
		if (head->right == NULL && head->left == NULL)
		{
			head->n = hold_n1;
			return (hold_n2);
		}
	}
	return (0);
}