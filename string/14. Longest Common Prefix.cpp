#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// lexicographically sort the array, then compare the first and last string , start by a ptr at 0
// TC= O(nlogn)
// SC= O(L)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string f=strs[0];
        string l=strs[strs.size()-1];
        bool flag=true; 
        string w="";
        int n=min(f.length(), l.length());
        for(int i=0;i<n;i++){
            if(f[i]==l[i])w+=f[i];
            else break;
        }
        return w;

        //TC = O(n*m)
        //SC = O(1)

        // string prefix=strs[0];
        // for(int i= 1;i<strs.size();i++){
        //     while(strs[i].find(prefix)!=0){
        //         prefix=prefix.substr(0,prefix.length()-1);
        //         if(prefix.empty())prefix="";
        //     }
        // }
        // return prefix;
    }

    
};