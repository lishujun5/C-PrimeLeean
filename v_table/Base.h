
#ifndef __BASE__
#define __BASE__
#include <iostream>
using namespace std;
class Base {
    public:
        virtual void f() { cout << "Base::f" << endl; }
        virtual void g() { cout << "Base::g" << endl; }
        virtual void h() { cout << "Base::h" << endl; }
        int a;
        Base():a(1){};
};
class Child:public Base
{
        virtual void f() { cout << "Child::f" << endl; }
        virtual void g() { cout << "Child::g" << endl; }
};
#endif