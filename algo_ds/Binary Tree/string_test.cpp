#include <iostream>
#include <string>
using namespace std;

void string_test(){
	string s;
	int a = 1;
	s += "Hellow";
	cout << s << endl;
	s += "how do you do?";
	cout << s << endl;
	cout << s.size() << endl;
	s += a.str();
	cout << s << endl;
}

int main(){
	string_test();
}