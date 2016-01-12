#include <iostream>
using namespace std;

int get_min(int *arr, int size){
	int min;
	int i = 0;
	min = arr[0];
	for(i = 0; i < size; i++){
		if(arr[i] <= min){
			min = arr[i];
		}
	}
	return min;
}

int coin_change(vector<int>& coins, int amount){
	int i = 0, j = 0;
	int num_coins = coins.size()
	int min = 0, temp = 0;
	int max = amount +10;
	int res[amount];
	int min[num_coins];
	res[0] = 0;

	for (i = 0; i < amount; i++){
		
		for(j = 0; j < num_coins; j++){
			temp = i - coins[j];
			if (temp < 0){
				min[j] = max;
			}
			else{
				min[j] = res[temp];
			}
			res[i] = 1 + get_min(&min[0],num_coins)
		}
	}
	if (res[amount-1] > amount){
		return -1;
	}
	else{
		return amount
	}
}

int main(){
	int arr[10];
	int i = 0;
	for (i = 0; i<10; i++){
		arr[i] = i;
	}
	cout << get_min(&arr[0],10) << endl;
}