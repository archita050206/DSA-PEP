#include<string>
using namespace std;

// concatenate the sorce string with itself (s+s), and then check whether goal is available in that or not

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return false;
        // int i=0;
        // while(i<s.length()){
        //     i++;
        //     char c=s[0];
        //     s=s.substr(1);
        //     s+=c;
        //     if(s==goal)return true;
            
        // }
        // return false;

        string temp=s+s;
        return (temp.find(goal)!=string::npos)?true:false;
    }
};