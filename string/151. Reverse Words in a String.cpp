#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void reverse(string &s, int l, int r){
        while(l<=r){
            swap(s[l],s[r]);
            l++;r--;
        }
    }
    string reverseWords(string s) {
        int i=0,n=s.length(),j=0,start=0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            while(i<n && s[i]!=' '){
                s[j]=s[i];
                i++;
                j++;
            }
            while(i<n && s[i]==' ')i++;
            if(i<n)
            {s[j]=' ';
            j++;
            }
        }
        s.resize(j);
        reverse(s,0,s.length()-1);
        for(int k=0;k<s.length();k++){
            if(s[k]==' '){
                reverse(s,start,k-1);
                start=k+1;
            }
            else if(k==s.length()-1){
                reverse(s,start,k);
            }
        }
        return s;
    }
};