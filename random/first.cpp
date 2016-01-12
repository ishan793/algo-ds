#include <iostream>
using namespace std;

int add_ptr(int *a, int *b, int *res){
	*res = *a + *b;
}
int main()
{
	int a = 1;
	int b = 2;
	int c = 0;

	add_ptr(&a, &b, &c);
	cout << "Result is" << c << endl;
  // char a[6];
  // int i;
  // for (i=0;i<5;i++){
  // 	*(a+i) = i+52;
  // }
  // a[5] = 0;
  // cout << "Hello World!" << a << endl;
}
