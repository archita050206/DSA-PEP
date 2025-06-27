#include<vector>
#include <string>
using namespace std;

// stack and string both ahve same tc but the time taken for stack processing is much more, stack is v slow and sc is more so prefer string

class Solution {
public:
    string removeDuplicates(string s) {

       string ans="";
        for(char c: s){
            if(!ans.empty() && ans.back()==c){
                ans.pop_back();
            }
            else{
                ans.push_back(c);
            }
        }
    //    s="";
    //     while(!st.empty()){
    //         char ch=st.top();
    //         st.pop();
    //         s=ch+s;
    //     }
        return ans;
      
    }
};