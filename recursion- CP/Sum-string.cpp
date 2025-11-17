#include<string>
#include<algorithm>
using namespace std;
class Solution {
  public:
  string summ(string s1,string s2){
      int i=s1.length()-1, j=s2.length()-1,carry=0;
      string ans="";
      while(i>=0 || j>=0||carry){
          int sum=carry;
          
          if(i>=0)sum+=s1[i]-'0';
          if(j>=0)sum+=s2[j]-'0';
          ans.push_back((sum%10)+'0');
          carry=sum/10;
          i--;j--;
      }
      reverse(ans.begin(), ans.end());
      return ans;
  }
    bool check(string s1, string s2, string s3){
        string sum=summ(s1,s2);
        if(s3.compare(0,sum.size(),sum)==0){
            if(sum.size()==s3.size())
            return true;
            return check(s2,sum,s3.substr(sum.size()));
            
        }
        return false;
    }
    bool isSumString(string &s) {
        // code here
        int n=s.length();
        for(int l1=1;l1<n;l1++){
            if(s[0]=='0' && l1>1)break;
            for(int l2=1;l1+l2<n;l2++){
                if(s[l1]=='0' && l2>1)continue;
                string s1=s.substr(0,l1);
                string s2=s.substr(l1,l2);
                string s3=s.substr(l1+l2);
                if(check(s1,s2,s3))return true;
            }
        }
        return false;
    }
};