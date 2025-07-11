#include<vector>
#include<string>

using namespace std;
class Solution
{
public:
    bool solver(int i, vector<int> &arr, int target, int n)
    {

        if (target == 0)
        {
            return true;
        }
        if (target < 0 || i >= n)
            return false;
        return solver(i + 1, arr, target - arr[i], n) ||
               solver(i + 1, arr, target, n);
    }

    bool isSubsetSum(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        return solver(0, arr, target, n);
    }
};