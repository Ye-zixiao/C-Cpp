#include<iostream>
#include<string>
#include<type_traits>
#include<utility>
#include<bitset>
#include<vector>
using namespace::std;

struct Solution {
	bitset<100> solution;
    size_t size(void) const{
        return solution.size();
    }
	Solution(const string& str) :solution(str){}
	Solution& update(size_t n, bool new_flag) {
		solution.set(n, new_flag);
		return *this;
	}
	size_t mark(const bitset<100>&item){
	    size_t cnt=0;
        for(size_t i=0;i<size();++i){
            if(item[i]==solution[i])
                ++cnt;
        }
        return cnt;
	}
};



int main(void)
{
    bitset<100> mine("10001000101111");
	Solution item("10001100101111");
	cout << item.update(21, true).solution << endl;
	cout<<item.mark(mine)<<endl;

	return 0;
}
