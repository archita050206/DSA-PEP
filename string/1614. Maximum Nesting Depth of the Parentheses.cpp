#include<string>
#include<climits>
using namespace std;

// for every '(' count++ and for every ')' count--, also keep track of the maximum value of count

class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=INT_MIN;
        for(char c: s){
            if(c=='('){
                count++;
            }
            else if(c==')'){
                count--;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};