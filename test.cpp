#include <iostream>
#include <algorithm>
using namespace std;

// Base class
class Shape 
{
	public:
	static int width = 1;
	static int height = 1;
	public:
	void setWidth(int w)
	{
		width++;
	}
	void setHeight(int h)
	{
		height++;
	}
	int getWidth()
	{
		return width;
	}
};

vector<int> hh(void)
{
	vector<int>obj;
	int i = 0;
	Shape qq = new Shape();
	for(i=0;i<20;i++)
	{
		qq.setWidth();
		obj.push_back(qq.getWidth());
	}
	return obj;
}
int main()
{
	vector<int>obj;
	obj = hh();
}