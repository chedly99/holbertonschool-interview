#include "lists.h"
#include <stdio.h>
/**
 * find_listint_loop - detext and return the start of a loop in a linked list
 * @head: pointer to the head of the linked list
 *
 * Return: adress of the node where the Loop starts or NULL if no loop found
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if (!head)
		return (NULL);

	fast = slow = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = (fast->next)->next;
		if (fast == slow)
		{
			slow = head;

			while (1)
			{
				if (slow == fast)
					return (slow);

				slow = slow->next;
				fast = fast->next;
			}
		}
	}

	return (NULL);
}
