#include "search_algos.h"

/**
 * print_array - Prints the array
 * @array: pointer to the first element of the array to print
 * @min: left side
 * @max: right side
 *
 * Return: void
 */
void print_array(int *array, int min, int max)
{
	int i;

	for (i = min; i < max; i++)
		printf("%d, ", array[i]);

	printf("%d\n", array[i]);
}
/**
 * BinarySearch - Perform the searche for a value
 * @array: pointer to the first element of the array to search in
 * @min: left boundary
 * @max: right bounday
 * @value: value to search for
 *
 * Return: Index where value is located or -1
 */
int BinarySearch(int *array, int min, int max, int value)
{
	int mid;

	if (min > max)
		return (-1);

	printf("Searching in array: ");
	print_array(array, min, max);

	if (min == max && array[max] == value)
		return (max);

	if (min == max && array[max] != value)
		return (-1);

	mid = min + (max - min) / 2;

	if ((mid == min || value != array[mid - 1]) && array[mid] == value)
		return (mid);

	if (array[mid] >= value)
		return (BinarySearch(array, min, mid, value));
	return (BinarySearch(array, mid + 1, max, value));
}
/**
 * advanced_binary - searches for a value in a sorted array
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index of the value if it's found, NULL othrwise
 */
int advanced_binary(int *array, size_t size, int value)
{

	if (!array || size == 0)
		return (-1);

	return (BinarySearch(array, 0, size - 1, value));
}
