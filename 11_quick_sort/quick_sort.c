#include <stdio.h>

#define MAX 10

void display(int *array)
{
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int quicksort(int array[], int start, int end)
{
	int pivot = start;
	int left = start;
	int right = end;
	int temp;

	if (left >= right)
		return (1);
	while (left < right)
	{
		while (array[left] < array[pivot] && left < right)
			left++;
		while (array[right] > array[pivot] && left < right)
			right--;
		if (left < right)
		{
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			if (array[left] == array[right])
				right--;
		}
	}
	temp = array[pivot];
	array[pivot] = array[right];
	array[right] = temp;
	quicksort(array, start, right - 1);
	quicksort(array, left + 1, end);
	return (0);
}

int main(void)
{
	int array[MAX] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
	display(array);

	int a = quicksort(array, 0, MAX - 1);
	display(array);
	printf("errorcode: %d", a);
	
}