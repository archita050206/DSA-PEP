#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if (arr[0] != 1)
            arr[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (abs(arr[i] - arr[i - 1]) > 1)
            {
                arr[i] = arr[i - 1] + 1;
            }
        }

        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     maxi=max(maxi,arr[i]);
        // }
        return arr[n - 1];
    }
};