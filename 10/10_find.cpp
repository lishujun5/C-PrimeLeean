#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// bool find_val(const int &a)
// {
//     return a<0?true:false;

// }
int main()
{
    vector<int> Nums = {1,2,4,5,6,4,7,8,42,-1,5};
    int val = 42;
    auto rst = find(Nums.begin(),Nums.end(),5);
    cout<<*rst<<endl;
    cout<<Nums.capacity()<<endl;
    cout<<Nums.size()<<endl;
    cout<<Nums.max_size()<<endl;
    Nums.erase(rst);
    rst = find(Nums.begin(),Nums.end(),5);
    cout<<*rst<<endl;
    return 0;
}