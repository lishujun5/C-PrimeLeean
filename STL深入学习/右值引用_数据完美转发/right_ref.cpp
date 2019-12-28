#include <iostream>

using namespace std;
void Foo(int &&x)
{
    //cout<<"x = "<<x<<endl;
    cout<<"void Foo(int &&x)"<<endl;
}
void Foo(int &x)
{
    //cout<<"x = "<<x<<endl;
    cout<<"void Foo(int &x)"<<endl;
}
#if 1
template<typename T>
void tmp(T &&x)
{
    Foo(std::forward<T>(x)); //使用std进行类型推导
}
#endif
int main(int argc, char *argv[])
{
    int x = 1;
    tmp(10);
    tmp(x);
    return 0;
}
