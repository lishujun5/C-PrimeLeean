#include "MyQueue.h"
using namespace std;
template <typename T>

Mynamespace::MyQueue<T>::MyQueue():p_start(0){}

template <typename T>
Mynamespace::MyQueue<T>::MyQueue(int size):p_start(0)
{
    cout<<"reserve size:"<<size<<endl;
    data.reserve(size);
}

template <typename T>
void Mynamespace::MyQueue<T>::pop()
{
    if (empty()) {
        return;
    } 
    p_start++;
    return;
}

template <typename T>
T& Mynamespace::MyQueue<T>::front() 
{
    return data[p_start];
}

template <typename T>
bool Mynamespace::MyQueue<T>::empty()  
{
    return p_start >= data.size();
}

template <typename T>
bool Mynamespace::MyQueue<T>::push(int x) {
    cout<<"****************"<<endl;
    data.push_back(x);
    return true;
}

template <typename T>
T& Mynamespace::MyQueue<T>::back()
{

}

template <typename T>
T& Mynamespace::MyQueue<T>::swap(T& other)
{

}

#if 0
int main()
{
    using namespace Mynamespace;
    MyQueue<int> a(10);
    a.push(1);
    a.front() = 2;
    cout<<a.front()<<endl;
    return 0;
}
#endif