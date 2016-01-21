#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// function to convert integer to string
string itos(int num){
	
	string s;
	int flag = 0;
	/*If the number is negative, add a negative sign
	and set a flag*/
	if (num < 0){
		s += "-";
		flag = 1;
		num = -num;
	}
	int temp;
	while(num != 0)
	{
		temp = num%10;
		num = num/10;
		s += '0'+ temp;
	}
	/*The set flag indicates where to start reversing the string*/
	if (flag == 1)
		reverse(s.begin()+1,s.end());
	else
		reverse(s.begin(),s.end());
	return s;
}

// function to convert string to integer
int sstoi(string s){
	int n = s.size();
	int sign = 1;
	int i = 0;

	/* in case the given number is negative
	set sign as -1 and start for loop from i = 1
	to ignore the negative sign*/
	if (s[0] == '-'){
		sign = -1;
		i = 1;
	}
	int res = 0;
	int cur = 0;
	for(; i < n; i++){
		cur = (int)s[i] - 48;
		res = res*10 + cur;
	}
	return sign*res;
}
int main(){
	string res = itos(25);
	int r = sstoi("-25");
	res += ": this is the string version";
	cout << res << endl;
	cout << "String conversion gives: " << r << endl;
	return 0;
}