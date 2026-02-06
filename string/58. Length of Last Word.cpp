#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int j=n-1,cnt=0;
        while(s[j]==' '){
            j--;
        }
        while(j>=0){
            if(s[j]==' ')break;
            else cnt++;
            j--;
        }
        return cnt;
    }
};