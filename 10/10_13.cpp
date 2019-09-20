#include <iostream>
#include <algorithm>
#include <vector>
#include<typeinfo>
using namespace std;
bool isEnough(const string &s)
{
    return s.size()<=3?true:false;
}
bool findshabi(const string &s)
{
    if(s == "dubo")
        return true;
    else
        return false;     
}
int main(int argc , char *argv[])
{
    const char *a[] = {"c++" , "c","python","c#","vb+","css","dubo","liuchao","lishujun"};
    vector<string> obj(a,a+sizeof(a)/sizeof(char *));
    vector<string>::iterator end_true= partition(obj.begin(),obj.end(),isEnough);
    //auto end_true = partition(obj.begin(),obj.end(),isEnough);
    for(auto e = obj.begin();e != end_true ; e++)
    {
        cout<<*e<<" ";
    }
    cout<<endl;
    auto print_string = [](const string &s){cout<<s<<endl;};
    for_each(end_true , obj.end() , print_string);
    cout<<endl;

    auto shabi = find_if(obj.cbegin() , obj.cend() , findshabi);
    cout<<"shabi is in "<<*shabi<<endl;
    return 0;
}