#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
    vector<vector<int>> ans(numRows);
   
    for(int i=0;i<numRows;i++){
        ans[i].resize(i+1);
        for(int j=0;j<(i+1);j++){
            if(j==0 || j==i)ans[i][j]=1;
            else ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans;
    }
};