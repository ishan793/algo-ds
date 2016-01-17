#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> a){
	
	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << "-";
	}
	cout << endl;
}
int delete_key(vector<int>& a, int key){
	int cur_ptr = 0, i = 0;
	for (i = 0; i< a.size() ; i++){
		if (a[i] != key){
			a[cur_ptr] = a[i];
			cur_ptr ++;
		}
	}
	return cur_ptr;
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
	print_vector(a);
	cout << delete_key(a,3) << endl;
	print_vector(a);
}