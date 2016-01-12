#include <iostream>
#include <vector>
using namespace std;

int bin_search(vector<int>& v){
	int max = v.size();
	int min = 0;
	int mid = (min+max)/2;
	
	if (v[0] == 1) {return 1;}
	else if (v[max-1] == 0){return -1;}
	while((max - min)>1) {
		
		// cout << "Mid " << mid << " Prev " << mid_prev << endl;
		cout << "Min is: "<<min<<" max is: "<<max<<" mid is: "<< mid <<endl;
		if (v[mid] == 0){
			min = mid;
			cout << "Greater"<<endl;
		}	
		else {
			max = mid;
			cout << "Smaller"<<endl;
		}
		mid = (min + max)/2;
	}
	// cout << "While loop ended" << endl;
	cout << "Min is: "<<min<<" max is: "<<max<<" mid is: "<< mid <<endl;
	// cout << "Min is: "<<v[min]<<" max is: "<<v[max] <<endl;
	return min + 2;
}

int main(){
	vector<int> first_vector(2);
	int i;
	for (i = 1; i < first_vector.size(); ++i)
	{	
		first_vector[i] = 1;
	}
	for (i = 0; i<first_vector.size();i++){
		cout << first_vector[i] << '-';
	}
	cout << endl;
	cout << bin_search(first_vector) << endl;
}
