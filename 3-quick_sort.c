#include "sort.h"
/**
 *partition - makes partition
 *@array: array
 *@lo: lowest
 *@hi: hightest
 *@size: size
 *Return: int
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = 0, aux = 0, i = 0, j = 0;

	pivot = array[hi];
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != j)
	{
		aux = array[i];
		array[i] = array[j];
		array[j] = aux;
		if (array[i] != array[j])
			print_array(array, size);
	}
	return (i);
}
/**
 *_quick_sort - checks if is unsorted
 *@array: array
 *@lo: lowest
 *@hi: hightest
 *@size: size
 *Return: void
 */
void _quick_sort(int *array, int lo, int hi, size_t size)
{
	int p = 0;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		_quick_sort(array, lo, p - 1, size);
		_quick_sort(array, p + 1, hi, size);
	}
}
/**
 *quick_sort - checks if is unsorted
 *@array: array
 *@size: size
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	_quick_sort(array, 0, size - 1, size);
}
