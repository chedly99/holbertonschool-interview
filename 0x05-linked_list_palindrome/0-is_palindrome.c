#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * is_palindrome - check is a singly list is a palindrome .
 * @head: head of the list .
 * Return: 1 ? palindrome : 0.
 */
int is_palindrome(listint_t **head)
{
	listint_t *counter = NULL;
	int stack[2068];
	int endStack = 0, frontStack = 0, r = 0;

	if (*head == NULL)
		return (1);
	counter = *head;
	while (counter)
	{
		stack[endStack++] = counter->n;
		counter = counter->next;
	}
	endStack--;
	r = endStack / 2 + 1;
	while (endStack >= r)
	{
		if (stack[frontStack++] != stack[endStack--])
			return (0);
	}
	return (1);
}
