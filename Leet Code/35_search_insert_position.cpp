#include <iostream>
#include <vector>
using namespace std;

int bin_search(vector<int>& v,int val){
	int size = v.size();
	int max = size;
	int min = 0;
	int mid = 0;
	int mid_prev = -1;
	
	while(mid != mid_prev){
		
		mid_prev = mid;
		mid = (min+max)/2;
		// cout << "Mid " << mid << " Prev " << mid_prev << endl;
		cout << "Min is: "<<min<<" max is: "<<max<<" mid is: "<< mid <<endl;
		if (v[mid] < val){
			min = mid;
			cout << "Greater"<<endl;
		}	
		else if (v[mid] > val) 	{
			max = mid;
			cout << "Smaller"<<endl;
		}
		else if (v[mid] == val){	
			cout << "Exact"<<endl;
			return mid;
		}
	}
	cout << "While loop ended" << endl;
	
	if (v[mid] > val) {
		cout << "+1" << endl;
		return mid;
	}
	else if (v[mid] < val){
		cout << "-1" << endl;
		return mid+1;
	}
	else{
		cout << "0" << endl;
		return mid;
	}
}

int main(){
	vector<int> first_vector;
	int i;
	for (i = 0; i < 2; ++i)
	{
		first_vector.push_back(2*i+1);
	}
	for (i = 0; i<first_vector.size();i++){
		cout << first_vector[i] << '-';
	}
	cout << endl;
	cout << bin_search(first_vector, 0) << endl;
}
