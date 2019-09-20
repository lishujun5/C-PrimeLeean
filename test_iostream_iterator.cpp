 
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
 using namespace std;
int main(int argc, char *argv[])
{
	std::vector<int> iVec = {54,3,89,7};
	std::ostream_iterator<int> out_iter(std::cout, " ");
	copy(iVec.cbegin(), iVec.cend(), out_iter);
 
	std::ostringstream oss;
	std::vector<std::string> vec = {"ab","bc","de"};
	std::vector<std::string> vec2 = { "ab", "bc", "de" };
 
	std::ostream_iterator<std::string> outIter(oss, ";");
	copy(vec.cbegin(),vec.cend(),outIter);
	std::string spliceStr = oss.str();
	std::cout << spliceStr << std::endl;
 
	oss.str("");	// 清空
	copy(vec2.cbegin(), vec2.cend(), outIter);
	std::string spliceStr2 = oss.str();
	std::cout << spliceStr2 << std::endl;
    
	getchar();
	return 0;
}
