#include <iostream>
using namespace std;

//Creates a Max Heap
void heapify(int* arr, int size, int index){
	int largest = index;
	int left = 2*index + 1; 
	int right = 2*index + 2;

	if (left < size && arr[left] > arr[largest]){
		largest = left;
	}

	if (right < size && arr[right] > arr[largest]){
		largest = right;
	}

	if (largest != index){
		int temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;

		heapify(arr, size, largest);
	}
}

void heapSort(int* arr, int size){
	for (int i = size/2 - 1; i >= 0; --i){
		heapify(arr, size, i);
	}

	for (int i = size - 1; i >= 0; --i){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		heapify(arr, i, 0);
	}
}

// int main(){
// 	int* arr = new int[5];
// 	int size = 5;
// 	arr[0] = 56;
// 	arr[1] = 12;
// 	arr[2] = 89;
// 	arr[3] = 59;
// 	arr[4] = 16;
// 	heapSort(arr, size);
// 	for(int i = 0; i < size; ++i){
// 		cout << arr[i] << endl;
// 	}
// 	cout << endl;
// }