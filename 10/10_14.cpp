#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
using namespace std;

class Play
{
    void operator () (int i)
    {
        cout<<i<<endl;
    }
};

int main()
{
    int a[] = { 1, 3, 4, 5};
    vector<int> vc(a, a+sizeof(a)/sizeof(int));
    for_each(vc.begin(), vc.end(), Play());
}