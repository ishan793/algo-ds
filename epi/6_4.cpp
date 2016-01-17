#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b){
	if (a>b)
		return a;
	else
		return b;
}
int check(vector<int> a){
	int n = a.size();
	int far_now = 0;
	int i,temp;

	for (i = 0; i <= far_now && far_now < n-1;i++){
		temp = i + a[i];
		far_now = max(far_now,temp);
		cout << far_now << " " << i << endl;
	}
	if (far_now >= n-1){
		cout << "True" << endl;
	}
	else
		cout << "Not happening" << endl;
	return 1;
}

int main(){
	vector<int> a(7);
	a[0] = 3;
	a[1] = 3;
	a[2] = 1;
	a[3] = 0;
	a[4] = 0;
	a[5] = 2;
	a[6] = 1;

	check(a);
}