#include <iostream>
#include<string>
#include<vector>
using namespace std;
 
string make_plural(size_t ctr, const string& word, const string& ending = "s")//此处觉得题目描述有误，应该是第三个形参赋予"s"，应为是字符串。
{
	//size_t表示的是unsigned int
	return (ctr > 1) ? word+ending : word;
}
int main(int argc, char *argv[])
{	
	cout<<"两单词的单数形式："<<make_plural(1,"success","es")<<"  "<<make_plural(1,"failure")<<endl;
	cout<<"两单词的复数形式："<<make_plural(2,"success","es")<<"  "<<make_plural(2,"failure")<<endl;
	return 0;//代表执行成功
}
