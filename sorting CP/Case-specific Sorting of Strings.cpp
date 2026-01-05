#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    string caseSort(string& s) {
        // code here
        int n=s.length();
        vector<char>lower,upper;
        for(int i=0;i<n;i++){
            if(islower(s[i]))lower.push_back(s[i]);
            else upper.push_back(s[i]);
        }
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        int lidx=0, uidx=0;
        for(int i=0;i<n;i++){
            if(islower(s[i]))s[i]=lower[lidx++];
            else s[i]=upper[uidx++];
        }
        return s;
    }
};