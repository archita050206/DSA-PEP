#include<vector>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        ans[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((i % 2) == 0)
                ans[i] = ans[i / 2];
            else
                ans[i] = ans[i / 2] + 1;
        }
        return ans;

        // vector<int>ans(n+1,0);
        //  for(int i=0;i<=n;i++){
        //      int cnt=0;
        //      int num=i;
        //      if(num==0)ans[i]=0;
        //      else{
        //      while(num>0){
        //          num=num&(num-1);
        //          cnt++;
        //      }
        //      ans[i]=cnt;
        //      }
        //  }
        //  return ans;
    }
};