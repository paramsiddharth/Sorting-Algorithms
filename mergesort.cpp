#include <iostream>
#include "array_ops"

void merge(int* array, int low, int mid, int high) {
	int i = low,
	    iEnd = mid,
	    j = mid + 1,
	    jEnd = high,
	    k = 0,
	    size = high - low + 1;
	int* tempArray = new int[size];

	while (i <= iEnd && j <= jEnd) {
		if (array[i] < array[j])
			tempArray[k++] = array[i++];
		else
			tempArray[k++] = array[j++];
	}
        while (i <= iEnd)
		tempArray[k++] = array[i++];
	while (j <= jEnd)
		tempArray[k++] = array[j++];	
	
	for (k = 0; k < size; k++)
		array[low + k] = tempArray[k];

	delete[] tempArray;
}

void sortAndMerge(int* array, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		
		sortAndMerge(array, low, mid);
		sortAndMerge(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}

void mergeSort(int* array, int size) { sortAndMerge(array, 0, size - 1); }

int main() {
	demonstrate(mergeSort, "Merge Sort");
	return 0;
}
