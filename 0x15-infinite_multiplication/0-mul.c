#include "holberton.h"
#include <stdlib.h>

/**
* error - prints error and exists program with status 98
*/
void error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * strlgth - finds the length of a string
 * @string: The string we are measuring
 * Return: returns the computed length
*/
int strlgth(char *string)
{
	int strlgth = 0;

	for (; string[strlgth] != '\0'; strlgth++)
	;

	return (strlgth);
}

/**
 * stoi - converts a given string into a integer array
 * @string: the string we are converting
 * Return: returns the array representation of the string
 */
int *stoi(char *string)
{
	int i = 0;
	int hold;
	int *large_num = NULL;
	(void) hold;

	/* ends program if one of given strings is a 0 */
	if (string[0] == '0')
	{
		_putchar('0');
		_putchar('\n');
		exit(0);
	}

	large_num = malloc(sizeof(int) * strlgth(string));
	if (large_num == NULL)
		error();

	for (i = 0;  string[i] != '\0'; i++)
	{
		if ((int)string[i] > 58 || (int)string[i] < 48)
			error();
		large_num[i] = string[i] - '0';
	}
	return (large_num);
}

/**
 * main - Entry point
 * @argv: command line arguments
 * @argc: command line argument count
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int *int_1 = NULL, *int_2 = NULL, *product = NULL, lgt_1, lgt_2;
	int hold_new, hold_carry;
	int i, j, k;
	int back_i = 0, back_j;

	if (argc != 3)
		error();
	int_1 = stoi(argv[1]);
	int_2 = stoi(argv[2]);
	lgt_1 = strlgth(argv[1]);
	lgt_2 = strlgth(argv[2]);
	product = malloc(sizeof(int) * (lgt_1 + lgt_2));
	if (product == NULL)
		error();
	for (i = lgt_1 - 1; i >= 0; i--)
	{
		hold_carry = 0;
		back_j = 0;
		for (j = lgt_2 - 1; j >= 0; j--)
		{
			hold_new = int_1[i] * int_2[j] + product[back_i + back_j] + hold_carry;
			hold_carry = hold_new / 10;
			product[back_i + back_j] = hold_new % 10;
			back_j++;
		}
		if (hold_carry > 0)
			product[back_i + back_j] += hold_carry;
		back_i++;
	}
	for (k = lgt_1 + lgt_2 - 1; k >= 0; k--)
	{
		if (k == lgt_1 + lgt_2 - 1 && product[k] == 0)
			continue;
		_putchar(product[k] + '0');
	}
	_putchar('\n');
	free(int_1);
	free(int_2);
	free(product);
	return (0);
}
