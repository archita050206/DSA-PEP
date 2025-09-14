#include<vector>
#include<string>
using namespace std;
class Solution {
  public:
    bool checkPangram(string& s) {
        //  code here
        vector<int>freq(26,0);
        for(char c: s){
            
            if(c>='A' && c<='Z')c+=32;
            if(c>='a' && c<='z')freq[c-'a']++;
            else continue;
            
        }
        for(int i:freq){
            if(i==0)return false;
        }
        return true;
    }
};