#include <iostream>
using namespace std;

void print_array(int *arr, int start, int end){
	int size = end - start + 1;
	
	for (int i = 0; i < size; ++i){
		cout << arr[start + i] << "-";
	}
	cout << endl;
}

void merge(int *res, int p, int q, int r){
	
	int l_ptr = 0;
	int r_ptr = 0;

	int l_size = q - p + 1;
	int r_size = r - q;
	
	int l_sa[l_size];
	int r_sa[r_size];

	int i = 0;
	
	for (i = 0; i < l_size; ++i){
		l_sa[i] = res[p+i];
	}

	for (i = 0; i < l_size; ++i){
		r_sa[i] = res[q+i+1];
	}
	
	for (i = p; i < r+1; ++i){
		if(l_ptr == l_size){
			res[i] = r_sa[r_ptr];
			r_ptr += 1;	
		} 
		else if (r_ptr == r_size){
			res[i] = l_sa[l_ptr];
			l_ptr += 1;
		}
		else if (l_sa[l_ptr] < r_sa[r_ptr]){
			res[i] = l_sa[l_ptr];
			l_ptr += 1;	
		}
		else{
			res[i] = r_sa[r_ptr];
			r_ptr += 1;
		}
	}
	
}

void merge_sort(int *a, int start, int end){
	int mid = 0;
	if(start < end){
		mid = (start + end)/2;

		merge_sort(a, start, mid);
		merge_sort(a, mid+1, end);
		merge(a,start,mid,end);

	}
}
int main(){

	int a[] = {8,2,8,9,2,3,4,6,8,1,7,6,8,9,2,3,4,5,7};
	int size = 19;
	merge_sort(a,0,size-1);

	print_array(a,0,size-1);
}