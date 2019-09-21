#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main(int argc , char *argv[])
{
    vector<int> obj;
    int a = 2;
    fill_n(back_inserter(obj),10,0);
    for(auto e : obj)
    {
        cout<<e<<endl;
    }
    cout<<obj.size()<<endl;
    cout<<setfill('x')<<setiosflags(ios::left)<<setw(2)<<a<<endl;
    return 0;
}