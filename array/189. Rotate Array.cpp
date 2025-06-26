#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> arr(n);

        int j = 0;
        for (int i = 0; i < k; i++) {
            arr[j++] = nums[n - k + i];
        }
        for (int i = 0; i < n - k; i++) {
            arr[j++] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = arr[i];
        }
    }
};

// rotate entire array, then rotate first k elements, then the next n-k elements
