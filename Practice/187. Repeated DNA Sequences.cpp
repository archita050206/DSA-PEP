#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string str) {
        unordered_set<string>seen,duplicate;
        vector<string>v;
        int i=0, j=9;
        while(j<str.length()){
            if (seen.find(str.substr(i,10))==seen.end()){
                seen.insert(str.substr(i,10));

            }
            else{
                duplicate.insert(str.substr(i,10));
            }
            i++;
            j++;
        }
    for(string k:duplicate){
        v.push_back(k);
    }
    return v;
        

    }
};