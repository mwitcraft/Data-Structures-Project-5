#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	srand((unsigned)time(0));

	int rando;

	for(int i = 0; i < 10; ++i){
		rando = rand() % 100;
		cout << i << ": " << rando << endl;
	}
}