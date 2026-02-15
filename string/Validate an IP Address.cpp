#include<string>
#include<climits>
using namespace std;
class Solution {
  public:
    
    int isValid(string &s) {
        // code here
        if(s.length()>15 || s.length()<7)return false;
        int j=0,dots=0,n=s.length();
        for(int i=0;i<=s.length();i++){
            if(i==n || s[i]=='.'){
                int len=i-j,rem=0;
                if(len==0 || len>3)return false;
                for(int k=j;k<i;k++){
                    if(s[k]>'9' || s[k]<'0')return false;
                    rem=rem*10+(s[k]-'0');
                }
                if(len>1 && s[j]=='0')return false;
                if(rem<0 || rem>255)return false;
                if(s[i]=='.')dots++;
                j=i+1;
            }
        }
        if(dots!=3)return false;
        return true;
        
    }
};