#include <vector>
using namespace std;

// lcm*gcd = a*b

class Solution
{

public:
    int gcd(int a, int b)
    {
        //   if(b==0)return a;
        //   return gcd(b, a%b);
        while (a != 0 && b != 0)
        {
            int t = a;
            a = b;
            b = t % a;
        }
        return a;
    }
    vector<int> lcmAndGcd(int a, int b)
    {
        // code here
        int val = gcd(a, b);
        vector<int> ans;
        ans.push_back((a * b) / val);
        ans.push_back(val);
        return ans;
    }
};