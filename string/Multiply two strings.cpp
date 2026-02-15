#include<string>
#include<vector>
using namespace std;
class Solution {
  public:
    string multiplyStrings(string &s1, string &s2) {
        // code here
        int sign=1;
        int n1=s1.length();
        int n2=s2.length();
        if(s1[0]=='-'){
            sign*=-1;
            s1=s1.substr(1);
            n1=s1.length();
        }
        if(s2[0]=='-'){
            sign*=-1;
            s2=s2.substr(1);
            n2=s2.length();
        }
        int i=0,j=0;
        while(i<n1 && s1[i]=='0'){
            i++;
        }
        if(i!=0)s1=s1.substr(i);
        if(s1=="")s1="0";
        while(j<n2 && s2[j]=='0'){
            j++;
        }
        
        if(j!=0)s2=s2.substr(j);
        if(s2=="")s2="0";
        if(s1=="0" || s2=="0")return "0";
        n1=s1.length(),n2=s2.length();
        vector<int>v(n1+n2,0);
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int pro=(s1[i]-'0')*(s2[j]-'0');
                pro=pro+v[i+j+1];
                v[i+j+1]=pro%10;
                v[i+j]+=pro/10;
            }
        }
        string ans="";
        int k=0;
        while(k<v.size() && v[k]==0)k++;
        while(k<v.size()){
            ans+=v[k]+'0';
            k++;
        }
        return (sign==-1)?'-'+ans: ans;
        
    }
};