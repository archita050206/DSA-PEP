#include<string>
#include<climits>
using namespace std;
class Solution {
  public:
    int myAtoi(string& s) {
        // code here
        int i=0,sign=1;
        int n=s.length();
        while(i<n && s[i]==' ')i++;
        if(i==n)return 0;
       
        if(s[i]=='-'||s[i]=='+'){
            if(s[i]=='-')sign=-1;
            i++;
            
        }
        s=s.substr(i);
        n=s.length();
        int num=0;
        for(int i=0;i<n;i++){
            if(s[i]>'9' || s[i]<'0')break;
            if(num> (INT_MAX-(s[i]-'0'))/10){
                return (sign==-1)?INT_MIN:INT_MAX;
            }
            num=num*10+(s[i]-'0');
           
        }
        return num*sign;
    }
};