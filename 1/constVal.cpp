#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<string> v6(10,"hi");
	int i = 42;
	const int  &r1 = i;
	const int &r2 = 42;
	const int &r3 = r1*2;
	//int &r4 = r1*2;
	double dval = 3.14;
	const int &r5 = dval;
	//r5 = 8;
	cout<<dval<<endl;
}