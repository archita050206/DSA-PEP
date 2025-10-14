#include<string>
using namespace std;
class Solution {
public:

    // we cannot compare 3 chars at once in in-built stack so we use a string instead to get hold of the indexed chars and check
    bool isValid(string s) {
        string st;
        for(char c: s){
            st+=c;
            if(st.size()>=3  && st[st.size()-3]=='a' && st[st.size()-2]=='b' && st[st.size()-1]=='c'){
                st.pop_back();
                st.pop_back();
                st.pop_back();
            }

        }
        return st.empty()?true:false;
    }
};