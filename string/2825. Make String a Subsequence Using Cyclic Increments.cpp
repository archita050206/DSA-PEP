#include<string>
#include<climits>
using namespace std;
class Solution {
public:
    
    bool canMakeSubsequence(string str1, string str2) {
        int n1=str1.length(),n2=str2.length();
        int i=0,j=0;
        // if(n2>n1){
            
        //     swap(str1,str2);
        // }
        // n1=str1.length(),n2=str2.length();
        while(i<n1 && j<n2){
            char ori=str1[i];
            char next=str1[i]=='z'?'a':ori+1;
            if(str2[j]==ori||str2[j]==next){
                j++;
            }
            i++;
        }
        return (j==n2);
    }
};