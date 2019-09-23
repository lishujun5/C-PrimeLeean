#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
bool sort_re(int a , int b)
{
    return a>b?true:false;
}
int main() {
    vector<int> num;
    int tmp;
    char c;
    string str;
    string b = "10 2 3 4 50 6 7 8 9";
    int accu = 0;
    for(auto &e :b)
    {
        if(isdigit(e))
        {
            cout<<e<<endl;
            accu += e;
        }
    }
    cout<<accu<<endl;
    if(getline(cin, str)) return 0;
    istringstream ist(str);
    while (ist>>tmp)
    {
        num.push_back(tmp);
        cout<<tmp<<endl;
    }
    sort(num.begin(),num.end(),sort_re);
    auto endNum = num.size();
    int i = 1;
    for(auto &e:num)
    {
        if(endNum != i)
        {
        	cout<<e<<",";
        }
        else
        {
            cout<<e;
        }
        i++;
    }
    return 0;
}