#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        int cnt=1;
        int target=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>target){
                cnt++;
                target=points[i][1];
            }
        }
        return cnt;
    }
};