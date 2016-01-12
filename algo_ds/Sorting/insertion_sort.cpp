#include <iostream>
#include <cstdlib>
using namespace std;

void print_array(int *arr, int start, int end){
	int size = end - start + 1;
	
	for (int i = 0; i < size; ++i){
		if (i == size - 1){
			cout << arr[start + i] ;	
		}
		else{
			cout << arr[start + i] << "-";
		}
	}
	cout << endl;
}

void insertion_sort(int *a, int size){
	int i = 0, j = 0;
	int key = 0;

	for (i = 1; i < size; i++){
		key = a[i];
		j = i-1;
		while (j > -1 && a[j] > key){
			a[j+1] = a[j];
			j -= 1;
		}
		a[j+1] = key;
	}
}

int main(){
	int size = 10;
	int a[size];
	int i = 0;

	for(i = 0; i<size; i++){
		a[i] = rand()%100;
	}

	print_array(a,0,size-1);
	insertion_sort(a,size);
	print_array(a,0,size-1);
}