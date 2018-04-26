#include <iostream>
using namespace std;

void selectionSort(int* arr, int size){
	int right;
	int left;
	int index;

	for(left = 0; left < size - 1; ++left){
		index = left;
		for(right = left + 1; right < size; ++right){
			if(arr[right] < arr[index]){
				index = right;
			}
		}
		int temp = arr[index];
		arr[index] = arr[left];
		arr[left] = temp;
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
// 	selectionSort(arr, size);
// 	for(int i = 0; i < size; ++i){
// 		cout << arr[i] << endl;
// 	}
// 	cout << endl;
// }