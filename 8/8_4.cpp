#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define LINE_LEN 1024
int main(int argc , char *argv[])
{
	vector<string> content;
	for(char** p = argv + 1 ; p != argv + argc ; p++)
	{
		char str[LINE_LEN];
		ifstream input(*p);
		if(input)
		{
			while(input.getline(str , LINE_LEN))
			{
				content.push_back(static_cast<string>(str));
			}
			input.close();
		}
		else
		{
			cerr<<"can,t open "<<*p<<endl;
		}
	}
	for(unsigned int e = 0 ; e < content.size() ; e++)
	{
		cout<<content.at(e)<<endl;
	}
	return 0;
}