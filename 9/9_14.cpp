#include <list>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	vector<string> str_content;
	list<char *> char_content = {"hello","world","!!!"};
	str_content.assign(char_content.begin() , char_content.end());
	return 0;
}