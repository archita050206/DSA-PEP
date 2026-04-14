#include<string>
#include<climits>
using namespace std;    
class Solution {
public:
    int minimumLength(string s) {
        int n=s.length(),i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return (j-i+1);
            }
            else{
                while(s[i]==s[i+1] && (i+1<j))i++;
                while(s[j]==s[j-1] && (j-1>i))j--;

            }
            i++;
            j--;
        }
        return (j-i)<0?0:(j-i+1);
    }
};