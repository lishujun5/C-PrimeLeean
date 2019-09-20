#include<iostream>                  
using namespace std;                
class const_val_lambda
{
public:
    const_val_lambda(int v) : val(v) {}
    int operator()() const { return val; } // 常量成员函数
private:
    int val;
};                                
int main()                          
{                                   
    int val = 0;                                    
    // auto const_val_lambda = [=](){ val = 3; }; wrong!!!
                                    
    auto mutable_val_lambda = [=]() mutable{ val = 3; };
    mutable_val_lambda();           
    cout<<val<<endl; // 0
                                    
    auto const_ref_lambda = [&]() { val = 4; };
    const_ref_lambda();             
    cout<<val<<endl; // 4
                                    
    auto mutable_ref_lambda = [&]() { val = 5; };
    mutable_ref_lambda();           
    cout<<val<<endl; // 5

    auto add_xy = [=](int x,int y)->int{return x+y;};
    cout<<add_xy(val,val)<<endl;

    auto add_x  = [=](int x)->int{return val+x;};
    cout<<add_x(10)<<endl; 
              
    return 0;      
}