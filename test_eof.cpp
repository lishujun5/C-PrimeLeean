
#include<iostream>   
#include <fstream>
using namespace std;
int main()
{
        std::ifstream input("test.txt");
        std::string tmp;
        int i = 0;
        while(!input.eof()) 
        {
            input >> tmp;
            std::cout << i++<<"th"<<tmp << std::endl;
        }
}
