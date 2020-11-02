#include <iostream>
#include "array_ops"

void selectionSort(int* array, int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		int temp = array[minIndex];
		array[minIndex] = array[i];
		array[i] = temp;
	}
}

int main() {
	demonstrate(selectionSort, "Selection Sort");
	return 0;
}
