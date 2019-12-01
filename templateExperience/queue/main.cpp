#include <iostream>
#include "MyQueue.h"
#include "MyQueue.cpp"
using namespace std;
int main()
{
    using namespace Mynamespace;
    MyQueue<int> a(10);
    a.push(1);
    a.front() = 2;
    cout<<a.front()<<endl;
    return 0;
}


