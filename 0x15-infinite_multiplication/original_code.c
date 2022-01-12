
 
#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
void error()
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

int stoi(char *string)
{
	int strlgth = 0;
	int i = 0;
	long long int increase = 10;
	long long int num = 0;
	int hold;

	for (; string[strlgth] != '\0'; strlgth++)
	{
		if ((int)string[strlgth] > 58 || (int)string[strlgth] < 48)
			error();
	}

	for(i = strlgth - 1; i >= 0; i--)
	{
		hold = string[i] - '0';
		if (i == strlgth - 1)
		{
			num = hold * 1;
			continue;
		}
		num = num + (hold * increase);
		increase = increase * 10;
	}
	return (num);
}

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	if (argc != 3)
		error();
	printf("%d\n", stoi(argv[1]));
	printf("%d\n", stoi(argv[2]));
	return (0);
}
