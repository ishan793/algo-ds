#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_vector(vector<int> a){
	int n = a.size();
	for (int i = 0; i<n; i++){
		if (i == n-1){
			cout << a[i] << endl;
		}
		else{
			cout << a[i] << "-";
		}
	}
}
void partition(vector<int>& arr,int start,int end, int* lower_ind, int* higher_ind){
	int i = start-1;
	int j = end;
	int x = arr[end];

	int k = start;
	while (k>i && k<j){
		if (arr[k] < x){
			i += 1;
			swap(&arr[k], &arr[i]);
			k += 1;
		}
		else if (arr[k] > x){
			j -= 1;
			swap(&arr[k], &arr[j]);
		}
		else{
			k += 1;
		}
	}
	swap(&arr[end], &arr[j]);
	*lower_ind = i;
	*higher_ind = j+1;
}

void quick_sort(vector<int>& a, int l, int h){
	int low = 0;
	int high = 0;
	if (l < h){
		// print_vector(a);
		partition(a,l,h, &low, &high);
		// print_vector(a);
		quick_sort(a, l, low);
		quick_sort(a,high,h);
	}
}

// void again_test(vector<int>& a){
// 	print_vector(a);
// }
// void test(vector<int>& a){
// 	print_vector(a);
// 	swap(&a[0],&a[1]);
// 	again_test(a);
// }
int main(){
	vector<int> a;

	for (int i = 0; i < 20; ++i)
	{
		/* code */
		a.push_back(20-i);
	}
	int lower = 0;
	int higher = 0;

	// test(a);
	print_vector(a);
	// swap(&a[0],&a[0]);
	// partition(&a,0,a.size()-1, &lower, &higher);
	quick_sort(a,0,a.size()-1);
	print_vector(a);
}