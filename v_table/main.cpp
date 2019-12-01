#include "Base.h"
#include <iostream>
using namespace std;
typedef void (*FUNC)(void);
int main()
{
    Base b;
    cout<<&b<<endl;
    cout<<&b.a<<endl;
    cout<<"sizeof(Base):"<<sizeof(Base)<<endl;
    cout<<"基类 b 的起始地址:"<<(int*)(&b)<<endl;
    cout<<"VTalbe 的起始地址:"<<(int**)(int*)(&b)<<endl;
    FUNC pf = NULL;
    pf = (FUNC)(*(int **)(*(int *)(&b)));
    pf();
    pf = (FUNC)(*((int **)(*(int *)(&b))+1));
    pf();
    pf = (FUNC)*((int**)*(int*)(&b)+2);
    pf();
 

    cout<<"***************子类没有覆写父类函数，调用父类函数************"<<endl;
    Child ch;
    pf = (FUNC)(*(int **)(*(int *)(&ch)));
    pf();
    pf = (FUNC)(*((int **)(*(int *)(&ch))+1));
    pf();
    pf = (FUNC)(*((int **)(*(int *)(&ch))+2));
    pf();
}