#ifndef __MYQUEUE__
#define __MYQUEUE__
#include <iostream>
#include <vector>
namespace Mynamespace 
{

    #if 0
    using std::vector;
    #else
    using namespace std;
    #endif
    template<typename T>
    class MyQueue
    {
        private:
            // store elements
            vector<T> data;       
            // a pointer to indicate the start position
            int p_start;            
        public:
            MyQueue();
            MyQueue(int size);
            /** Qinsert an element into the MyQueue. Return true if the operation is successful. */
            bool push(int x);
            /** Delete an element from the MyQueue. Return true if the operation is successful. */
            void pop();
            /** Get the Qfront item from the MyQueue. */
            T& front();
            /** Checks whether the MyQueue is empty or not. */
            bool empty();
            /*size of MyQueue*/
            int size();
            /*get last element of T*/
            T& back();
            /*swap two element of MyQueue*/
            T& swap(T& other);
    };
}
#endif