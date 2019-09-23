#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
    map<char,size_t>word_count;
    map<char,int>word_order;
   	set<char>save;
    int i = 0;
    string word;
    cin>>word;
    for(auto &e:word)
    {
        if(save.find(e) != save.end())
        {
        	word_count[e]++;
        }
        else
        {
        	word_count[e]++;
            word_order[e] = i++;
            save.insert(e);
        }
    }
    i = 0;
 
    cout<<"this first version"<<endl;
    while(!save.empty())
    {
        for(auto &q : save)
        {
           if(word_order[q] == i)
            {
                cout<<q<<":"<<word_count[q]<<";";
                save.erase(q);
                i++;
                //break;
            }
        }
    }
    cout<<endl;
    return 0;
}