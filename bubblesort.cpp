#include <iostream>
#include "array_ops"
using namespace std;

void bubbleSort(int* array, int size) {
	for (int i = 0; i < size - 1; i++) {
		bool swaps = false;
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j + 1] < array[j]) {
				swaps = true;
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
		if (!swaps)
			break;
	}
}

int main() {
	demonstrate(bubbleSort, "Bubble Sort");
	return 0;
}