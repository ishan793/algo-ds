#include <iostream>
using namespace std;

int max_cross_subarray(int *a, int low, int mid, int high){
	
	int i;
	int left_sum = 0, right_sum = 0, sum = 0;
	int max = -100;

	for (i = mid; i>low-1; i--){
		left_sum += a[i];
		if (left_sum > max){
			max = left_sum;
		}
	}
	sum += max;

	max = -1;
	for (i = mid+1; i<high+1; i++){
		right_sum += a[i];
		if(right_sum > max){
			max = right_sum;
		}
	}
	
	sum += max;

	return sum;
}

int max_subarray(int *a, int low, int high){
	if(high == low){return a[high];}
	else{
		int mid = (low+high)/2;
		int cross_max = max_cross_subarray(a,low, mid, high);
		int left_max = max_subarray(a,low,mid);
		int right_max = max_subarray(a,mid+1,high);

		if (cross_max > left_max && cross_max > right_max){
			return cross_max;
		}
		else if (right_max > left_max && cross_max < right_max){
			return right_max;
		}
		else{
			return left_max;
		}
	}
}
int main(){
	int size = 10;
	int a[] = {1,2,5,3,13,2,3,1,1,5};
	int ans = max_subarray(a,0,9);
	cout << ans << endl;;
}
