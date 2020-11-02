#include <iostream>
#include "array_ops"

int partition(int* array, int low, int high) {
	int i = low + 1,
	    j = high;

	while (i < j) {
		while (array[i] <= array[low] && i < high)
			i++;
		while (array[j] > array[low] && j > low)
			j--;
		if (i < j) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	int temp = array[j];
	array[j] = array[low];
	array[low] = temp;

	return j;
}

void divideAndSort(int* array, int low, int high) {
	if (low < high) {
		int partitionIndex = partition(array, low, high);

		divideAndSort(array, low, partitionIndex - 1);
		divideAndSort(array, partitionIndex + 1, high);
	}
}

void quickSort(int* array, int size) {
	divideAndSort(array, 0, size - 1);
}

int main() {
	demonstrate(quickSort, "Quick Sort");
	return 0;
}
