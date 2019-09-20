#ifndef Cccc//第一次包含本头文件时，#ifndef判断为真，预处理器将处理后面的内容直到#endif，此时的预处理变量Cccc已定义
#define Cccc//第二次包含本头文件时，#ifndef判断为假，预处理器将忽略后面的内容
 
#include <string>
#include <iostream>
using namespace std;
class Screen {
public:
	typedef std::string::size_type pos;//std库中的string类的sizetype类型
 
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c)
	{
	}
	Screen& setCursor(pos cursorVal) {cursor = cursorVal; return *this;}
	char get() const { cout<<cursor<<endl;return contents[cursor]; }
	char get(pos r, pos c) const { return contents[r * width + c]; }
 
private:
	pos cursor;
	pos height, width;
	std::string contents;
};
 
 
int main()
{
	Screen screen(1,5,'a');
	cout<<screen.setCursor(0).get()<<endl;
	return 0;
}
#endif//只要简单的加上就好了，无视C++中的作用域规则,作用是防止头文件被重复包含
