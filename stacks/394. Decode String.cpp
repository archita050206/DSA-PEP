#include<stack>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<string>st1;
        stack<int>st2;
        string currStr="";
        int currNum=0;
        for (char c: s){
            if(isdigit(c)){
                currNum=currNum*10+(c-'0');
            }
            else if(c=='['){
                st1.push(currStr);
                st2.push(currNum);
                currStr="";
                currNum=0;
            }
            else if(c==']'){
                int repeat=st2.top();
                st2.pop();
                string word=st1.top();
                st1.pop();
                string temp="";
                for(int i=0;i<repeat;i++)temp+=currStr;
                currStr=word+temp;
            }
            else{
                currStr+=c;
            }
        }
        return currStr;
    }
};