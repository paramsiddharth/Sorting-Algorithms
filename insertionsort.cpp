#include <iostream>
#include "array_ops"

void insertionSort(int* array, int size) {
	for (int i = 1; i < size; i++) {
		if (array[i] < array[i - 1]) {
			int current = array[i];
			int j = i - 1;
			while (j >= 0 && array[j] > current) {
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = current;
		}
	}
}

int main() {
	demonstrate(insertionSort, "Insertion Sort");
	return 0;
}
