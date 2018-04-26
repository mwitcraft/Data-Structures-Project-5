#include <iostream>
using namespace std;

int partition(int* arr, int low, int high){
	int pivot = arr[high];

	int smallIndex = (low - 1);

	for(int j = low; j < high; ++j){
		if(arr[j] <= pivot){
			++smallIndex;
			int temp = arr[smallIndex];
			arr[smallIndex] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[smallIndex + 1];
	arr[smallIndex + 1] = arr[high];
	arr[high] = temp;
	return (smallIndex + 1);
}

void quickSort(int* arr, int low, int high){
	if(low < high){
		int index = partition(arr, low, high);

		quickSort(arr, low, index - 1);
		quickSort(arr, index + 1, high);
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
// 	quickSort(arr, 0, size - 1);
// 	for(int i = 0; i < size; ++i){
// 		cout << arr[i] << endl;
// 	}
// 	cout << endl;
// }