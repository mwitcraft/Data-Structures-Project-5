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
		if(i == size - 1){
			cout << arr[i] << endl;
		} 
		else {
			cout << arr[i] << ", ";
		}
	}
}

int main(){
	//Set seed for random number generator
	srand((unsigned)time(0));

/* Begin testing sorting algorithms */	

	//Sorting methods test size
	int size = 30;

	//Initialize A & B
	A = new int[size];
	int* B = new int[size];

	//Fill A with random numbers
	for(int i = 0; i < size; ++i){
		A[i] = rand() % 30;
	}

	//Copy contents from A to B and print B
	myCopy(A, B, size);
	cout << "Unsorted: " << endl;
	//Just print out first 10 elements
	print(B, 10);
	cout << endl;

	//Perform Insertion Sort on B and print
	insertionSort(B, size);
	cout << "Insertion Sort: " << endl;
	print(B, 10);
	cout << endl;

	//Replace B with unsorted values
	myCopy(A, B, size);
	cout << "Unsorted: " << endl;
	print(B, 10);
	cout << endl;	

	//Perform Selection Sort on B and print
	selectionSort(B, size);
	cout << "Selection Sort: " << endl;
	print(B, 10);
	cout << endl;

	//Replace B with unsorted values
	myCopy(A, B, size);
	cout << "Unsorted: " << endl;
	print(B, 10);
	cout << endl;

	//Perform Quick Sort on B and print
	quickSort(B, 0, size - 1);
	cout << "Quick Sort: " << endl;
	print(B, 10);
	cout << endl;

	//Replace B with unsorted values
	myCopy(A, B, size);
	cout << "Unsorted: " << endl;
	print(B, 10);
	cout << endl;

	//Perform Heap Sort on B and print
	heapSort(B, size);
	cout << "Heap Sort: " << endl;
	print(B, 10);
	cout << endl;

	delete[] A;		

/* End testing sorting algorithms */
/*--------------------------------*/
/* Begin finding average times */

	//Steps through each number in X, corresponding to the number of elements
	//in the array to be sorted
	for(int k = 0; k < 5; ++k){
		//Arrays that will be sorted of sizes in X
		A = new int[X[k]];
		B = new int[X[k]];

		//Arrays to store the time needed to sort
		double* insertionSortTimes 	= new double[10];
		double* selectionSortTimes 	= new double[10];
		double* quickSortTimes 		= new double[10];
		double* heapSortTimes 		= new double[10];

		//Step through each size 10 times to get enough data to find averages
		for(int q = 0; q < 10; ++q){
			clock_t start;
			clock_t end;

			size = X[k];
			//Fill A with 'size' random numbers
			for(int i = 0; i < size; ++i){
				A[i] = rand() % size;
			}
			//Copy A into B
			myCopy(A, B, size);
			//Start time
			start = clock();
			//Perform sort
			insertionSort(B, size);
			//End time
			end = clock();
			//Store time in array
			insertionSortTimes[q] = ((double)(end - start));

			//Unsort B by copying A back into B
			myCopy(A, B, size);
			//Start time
			start = clock();
			//Perform sort
			selectionSort(B, size);
			//End time
			end = clock();
			//Store time in array
			selectionSortTimes[q] = ((double)(end - start));

			//Unsort B by copying A back into B
			myCopy(A, B, size);
			//Start time
			start = clock();
			//Perform sort
			quickSort(B, 0, size - 1);
			//End time
			end = clock();
			//Store time in array
			quickSortTimes[q] = ((double)(end - start));

			//Unsort B by copying A back into B
			myCopy(A, B, size);
			//Start time
			start = clock();
			//Perform sort
			heapSort(B, size);
			//End time
			end = clock();
			//Store time in array
			heapSortTimes[q] = ((double)(end - start));
		}

		//Calculate averages
		double insertionSum = 0;
		double selectionSum = 0;
		double quickSum 	= 0;
		double heapSum 		= 0;		
		for(int i = 0; i < 10; ++i){
			insertionSum 	+= insertionSortTimes[i];
			selectionSum 	+= selectionSortTimes[i];
			quickSum 		+= quickSortTimes[i];
			heapSum 		+= heapSortTimes[i];
		}
		insertionSum 	= insertionSum/10;
		selectionSum 	= selectionSum/10;
		quickSum 		= quickSum/10;
		heapSum 		= heapSum/10;

		//Display Averages
		cout << "Average time needed to sort arrays of size " << X[k] << " using:" << endl;
		cout << "INSERTION SORT: \t" << insertionSum << endl;
		cout << "SELECTION SORT: \t" << selectionSum << endl;
		cout << "QUICK SORT: \t\t" << quickSum << endl;
		cout << "HEAP SORT: \t\t" << heapSum << endl;
		cout << endl;
	}
}
/* End finding average times */



