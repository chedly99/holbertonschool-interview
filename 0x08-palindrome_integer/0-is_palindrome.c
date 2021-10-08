#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - check if a palindrome
 * @n: unsigned long integer
 * Return: 1 if palindrome 0 if not
 */
int is_palindrome(unsigned long n)
{
	int r = 0;
	int rev = 0;
	int ref = n;

	while (n != 0)
	{
		r = n % 10;
		rev = rev * 10 + r;
		n = n / 10;
	}
	if (rev == ref)
		return (1);
	return (0);
}
