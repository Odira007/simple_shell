/**
 * insertion_sort - Recursive function to sort an array using
 * insertion sort
 * @arr: an array to be sorted
 * @n: the divisor
 *
 * Return: void
 */
void insertion_sort(int arr[], int n)
{
	int last;
	int j;

	if (n <= 1)
		return;

	insertion_sort(arr, n - 1);

	last = arr[n - 1];
	j = n - 2;

	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
}
