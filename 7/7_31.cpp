#ifndef INCLUDE_X_Y
#define INCLUDE_X_Y
#include <iostream>
using namespace std;
class Y;
//class X;
class X
{
	public:
		X() = default;
		X(int a):xx(a){}
		int get(){return xx;}
	private :
		Y *p_y;
		int xx;
};
class Y
{
	public:
		Y() = default;
		Y(int a):yy(a){}
		int get(){return yy;}
	private :
		X x;
		int yy;
};
int main()
{
	
	X x(5);
	Y y;
	cout<<x.get()<<endl;
	cout<<y.get()<<endl;
	return 0;
}
#endif