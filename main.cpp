#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	clock_t start, end;
	double cpu_time_used;

	start = clock();

	srand((unsigned)time(0));

	int rando;

	for(int i = 0; i < 10; ++i){
		rando = rand() % 100;
		cout << i << ": " << rando << endl;
	}

	end = clock();
	cpu_time_used = ((double) (end - start));

	cout << "TIME: " << cpu_time_used << endl;
}