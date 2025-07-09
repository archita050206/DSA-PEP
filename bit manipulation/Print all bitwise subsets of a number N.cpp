#include <vector>
using namespace std;

class Solution
{
    /*
        a bitwise subset is a number:
        -> from 0 to n
        -> (n&i)==i
    */

public:
    vector<int> printSubsets(int n)
    {

        vector<int> ans;
        for (int i = n; i >= 0; i--)
        {
            if ((n & i) == i)
                ans.push_back(i);
        }
        return ans;
    }
};
