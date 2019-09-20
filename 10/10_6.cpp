#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc , char *argv[])
{
    vector<int> obj;
    fill_n(back_inserter(obj),10,0);
    for(auto e : obj)
    {
        cout<<e<<endl;
    }
    return 0;
}