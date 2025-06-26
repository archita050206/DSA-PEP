#include <vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

// anagrams have the freq of every alphabet same and the length of both the words is same

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp1,mp2;
        for(char c: s){
            mp1[c]++;
        }
        for(char c: t){
            mp2[c]++;
        }
        if(mp1==mp2 && mp1.size()==mp2.size())return true;
        return false;
    }
};