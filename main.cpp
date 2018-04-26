#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
using namespace std;

int* A;
int X[] = {1000, 2000, 3000, 4000, 5000};

void myCopy(int* from, int* to, int size){
	for(int i = 0; i < size; ++i){
		to[i] = from[i];
	}
}

void print(int* arr, int size){
	for(int i = 0; i < size; ++i){
		cout << arr[i] << endl;
	}
}

int main(){
	//Set seed for random number generator
	srand((unsigned)time(0));

	//Initialize A & B
	A = new int[5];
	int* B = new int[5];

	//Fill A with random numbers
	for(int i = 0; i < 5; ++i){
		A[i] = rand() % 100;
	}

	//Copy contents from A to B and print B
	myCopy(A, B, 5);
	cout << "Unsorted: " << endl;
	print(B, 5);
	cout << endl;

	//Perform Insertion Sort on B and print
	insertionSort(B, 5);
	cout << "Insertion Sort: " << endl;
	print(B, 5);
	cout << endl;

	//Replace B with unsorted values
	myCopy(A, B, 5);
	cout << "Unsorted: " << endl;
	print(B, 5);
	cout << endl;	

	//Perform Selection Sort on B and print
	selectionSort(B, 5);
	cout << "Selection Sort: " << endl;
	print(B, 5);
	cout << endl;

	//Replace B with unsorted values
	myCopy(A, B, 5);
	cout << "Unsorted: " << endl;
	print(B, 5);
	cout << endl;

	//Perform Quick Sort on B and print
	quickSort(B, 0, 5 - 1);
	cout << "Quick Sort: " << endl;
	print(B, 5);
	cout << endl;

	//Replace B with unsorted values
	myCopy(A, B, 5);
	cout << "Unsorted: " << endl;
	print(B, 5);
	cout << endl;

	//Perform Heap Sort on B and print
	heapSort(B, 5);
	cout << "Heap Sort: " << endl;
	print(B, 5);
	cout << endl;		



	// clock_t start, end;
	// double cpu_time_used;

	// start = clock();

	// end = clock();

	// cpu_time_used = ((double) (end - start));

	// cout << "TIME: " << cpu_time_used << endl;
}



