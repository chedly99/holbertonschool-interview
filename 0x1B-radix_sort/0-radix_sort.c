#include "sort.h"

/**
 * getMaximum - find the maximum digit of an array
 *
 * @array: array of integers
 * @size: size of the array.
 *
 * Return: the biggest element of the array.
 */
int getMaximum(int *array, int size)
{
int maxNum, i;

maxNum = array[0];

for (i = 1; i < size; i++)
{
if (array[i] > maxNum)
maxNum = array[i];
}
return (maxNum);
}
/**
 * getDigit - get the significant digit
 * @number: num
 * @position: postion of the digit to be extracted
 * Return: digit integer
 */
int getDigit(int number, int position)
{
	return ((number / position) % 10);
}

/**
 * countingSort - the main func
 * @array: array
 * @exp: exp
 * @size: size of the array
 * Return: None
 */
void countingSort(int *array, int exp, int size)
{
	int i;
	int digit;
	int counting[10] = { 0 };
	int *sortedArray = NULL;
	int k;


	sortedArray = malloc(sizeof(int) * size);
	if (!sortedArray)
		return;

	for (i = 0; i < size; i++)
		counting[getDigit(array[i], exp)]++;

	for (i = 1; i < 10; i++)
		counting[i] += counting[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		digit = getDigit(array[i], exp);
		k = --counting[digit];
		sortedArray[k] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = sortedArray[i];

	print_array(array, (size_t)size);
	free(sortedArray);
	sortedArray = NULL;
}
/**
 * radix_sort - sort an array using the radix algo
 * @array: array to sort
 * @size: size of tharray
 * Return: nothing void
 */
void radix_sort(int *array, size_t size)
{
	int maximum = getMaximum(array, (int)size);
	int exp = 1;

	if (size < 2 || !array)
		return;

	for (; maximum / exp > 0; exp *= 10)
		countingSort(array, exp, (int)size);
}
