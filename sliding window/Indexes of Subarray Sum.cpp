#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        // code here
        int i = 0, j = 0, n = arr.size(), sum = 0, ansi = -1, ansj = -1;
        while (j < n)
        {
            sum += arr[j];
            while (sum > target)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == target)
            {

                ansi = i;
                ansj = j;
                return vector<int>{ansi + 1, ansj + 1};
            }

            j++;
        }
        return vector<int>{-1};
    }
};