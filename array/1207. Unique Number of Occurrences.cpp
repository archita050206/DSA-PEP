#include <unordered_map>
#include <vector>
#include<set>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int num:arr){
            freq[num]++;
        }
        set<int>s;
        for( auto p: freq){
            s.insert(p.second);
        }
        if(s.size() != freq.size())return false;
        return true;
    }
};
//get the sum of the array elements, subtract the sum of unique elements (qs->to check if 2 elements have the same freq)