// User function template for C++
#include<string>
#include<vector>
using namespace std;
class Solution {
  public:

    int isRepeat(string s) {
        // Your code goes here
        int n=s.length();
        
        for(int len=1;len<=n/2;len++){
            if(n%len!=0)continue;
            string sub=s.substr(0,len);
            string temp="";
            for(int i=0;i<n/len;i++){
                temp+=sub;
            }
            if(temp==s)return 1;
        }
        return 0;
    }
};