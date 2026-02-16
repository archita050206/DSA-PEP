#include<string>
#include<vector>
using namespace std;
class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string curr="1";
        for(int i=2;i<=n;i++){
            string next="";
            int cnt=1;
            for(int j=1;j<curr.size();j++){
                if(curr[j]==curr[j-1])cnt++;
                else{
                    next+=to_string(cnt);
                    next+=curr[j-1];
                    cnt=1;
                }
                
                
            }
            next+=to_string(cnt);
            next+=curr.back();
            curr=next;
        }
        return curr;
    }
};